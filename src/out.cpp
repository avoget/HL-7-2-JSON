#include "out.hpp"

//=================== BaseOut

void BaseOut::addType(BaseType::TypePtr const & type){
	_types.push_back(type);
}
void BaseOut::printFields(ostream & out, BaseField::FieldPtr & fieldsRoot){
	for(TypeList::iterator it = _types.begin(); it != _types.end(); ++it){
		BaseField::FieldPtr field = fieldsRoot->find(*it);
		if(field){
			out << " \"" << field->get() << "\"";
		}
	}
}

//=================== ComplexOut

void ComplexOut::print(ostream & out, BaseField::FieldPtr & fieldsRoot){
	out << "\"" << title() << "\": {\n";
	children().first();
	while( !children().isEnd() ){
		children().get()->print(out, fieldsRoot);
		children().next();
	}
	out << "\n}\n";
}
ContainerBase<BaseOut> & ComplexOut::children(){
	return _children;
}

//=================== SimpleOut

void SimpleOut::print(ostream & out, BaseField::FieldPtr & fieldsRoot){
	out << "\"" << title() << "\":";
	printFields(out, fieldsRoot);
	out << "\n";
}
ContainerBase<BaseOut> & SimpleOut::children(){
	return _children;
}
