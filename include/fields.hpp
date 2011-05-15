#ifndef fields_h
#define fields_h

#include "types.hpp"
#include "parser.hpp"

class BaseField : public Composite<BaseField> {
	BaseType & _type;
public:
	typedef typename Composite<BaseField>::BasePtr BasePtr;
	BaseField(BaseType &type) : _type(type) {}
	virtual ~BaseField(){}

	virtual string get() = 0;
	virtual void set(string value, char sep) = 0;

	static BasePtr create(const ContainerBase<BaseType> & typesRoot);
	
	BaseType & type(){
		return _type;
	}
};

class ComplexField : public BaseField {
	Container<BaseField> _children;
	static char nextSep(char sep){
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
public:
	ComplexField(BaseType &type) : BaseField(type) {}
	string get(){
		return string();
	}
	void set(string value, char sep){
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
			}
		}
	}
	ContainerBase<BaseField> & children() {
		return _children;
	}
};

class SimpleField : public BaseField {
	string _value;
	EmptyContainer<BaseField> _children;
public:
	SimpleField(BaseType &type) : BaseField(type) {}
	string get(){
		return _value;
	}
	void set(string value, char sep){
		_value = value;
	}
	ContainerBase<BaseField> & children() {
		return _children;
	}
};

BaseField::BasePtr BaseField::create(const ContainerBase<BaseType> & typesRoot){
	///!!!
	BasePtr ret;

	return ret;
}



#endif	//fields_h