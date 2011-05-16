#include <iostream>

#include "types.hpp"

string BaseType::id() const {
	return _typeId;
}
string BaseType::name() const {
	return _name;
}
string BaseType::description() const {
	return _description;
}
void BaseType::id(string const & typeId){
	_typeId = typeId;
}
void BaseType::name(string const & name){
	_name = name;
}
void BaseType::description(string const & description){
	_description = description;
}
void BaseType::additional(const StringList & values){
}

//=================== SimpleType

ContainerBase<BaseType> & SimpleType::children() {
	return _children;
}
void SimpleType::dump(){
	std::cout << "BaseType::dump() _typeId=" << _typeId << " ,_name=" << _name << ", _description=" << _description << "\n";
}

//=================== IdType

void IdType::additional(const StringList & values){
	//!!! insert into _set
//		_set = values;
}
bool IdType::validate(string const & value) const {
	return _set.find(value) != _set.end();
}

//=================== StringType

bool StringType::validate(string const & value) const {
	return true;
}

//=================== DateType

bool DateType::validate(string const & value) const {
	//!!!
	return false;
}

//=================== ComplexType

bool ComplexType::validate(string const & value) const {
	bool ret = false;
	_children.first();
	while( ! _children.isEnd() ){
//			ret
	}
	// !!!!
	return true;
}
ContainerBase<BaseType> & ComplexType::children() {
	return _children;
}
void ComplexType::dump(){
	std::cout << "BaseType::dump() _typeId=" << _typeId << " ,_name=" << _name << ", _description=" << _description << "\n";
	children().first();
	while( !children().isEnd() ){
		children().get()->dump();
		children().next();
	}
}


//
