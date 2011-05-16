#include "iostream"

#include "fields.hpp"
#include "parser.hpp"

//=================== ComplexField

char ComplexField::nextSep(char sep){
	char ret = sep;
	switch(sep){
		case '|':
			ret = '^';
			break;
		case '^':
			ret = '&';
			break;
	}
	return ret;
}
string ComplexField::get() const {
	return string();
}
void ComplexField::set(string value, char sep){
	if( value[0] != sep){
		value = sep + value;
		Parser::Parser parser;
		// !!! may throw exception
		Parser::Parser::StringVector v = parser.parseString(value, sep);
		children().first();
		Parser::Parser::StringVectorIterator it = v.begin();
		while ( (! children().isEnd()) && (it != v.end()) ) {
			// !!! what is sep ?
			children().get()->set(*it, nextSep(sep));
			++it;
			children().next();
		}
	}
}
ContainerBase<BaseField> & ComplexField::children() {
	return _children;
}
void ComplexField::dump(){
	std::cout << "ComplexField::dump() _typeId=" << type().id() << ", this=" << (int)this << "\n";
	children().first();
	while( !children().isEnd() ){
		children().get()->dump();
		children().next();
	}
}
BaseField::FieldPtr ComplexField::find(TypePtr const & atype){
	FieldPtr ret;
	if( atype->id() == type().id() ){
		ret = this;
		return ret;
	}
//	ContainerBase<BaseField> con
	children().first();
	while( !children().isEnd() ){
		ret = children().get()->find(atype);
		if(ret){
			break;
		}
		children().next();
	}
	return ret;
}

//=================== SimpleField

string SimpleField::get() const {
	return _value;
}
void SimpleField::set(string value, char sep){
	_value = value;
}
ContainerBase<BaseField> & SimpleField::children() {
	return _children;
}
void SimpleField::dump(){
	std::cout << "SimpleField::dump() _typeId=" << type().id() << ", this=" << (int)this << "\n";
	std::cout << "value=" << get() << "\n";
}
BaseField::FieldPtr SimpleField::find(TypePtr const & atype){
	FieldPtr ret;
	if( atype->id() == type().id() ){
		ret = this;
	}
	return ret;
}

//=================== BaseField

BaseField::FieldPtr BaseField::create(BaseField::TypePtr const & typesRoot){
	BaseField::FieldPtr ret;
	ContainerBase<BaseType> & tCntr = typesRoot->children();
	if( tCntr.container() ){
		ret = new ComplexField(*typesRoot);
		ContainerBase<BaseField> & fCntr = ret->children();
		tCntr.first();
		while(!tCntr.isEnd()){
			fCntr.add( create(tCntr.get() ) );
			tCntr.next();
		}
	}else{
		ret = new SimpleField(*typesRoot);
	}
	return ret;
}


//
