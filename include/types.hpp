#ifndef types_h
#define types_h

#include <iostream>
#include <string>
#include <set>
#include <list>

using std::string;

#define CSTR_IDTYPE_NAME			"ID"
#define CSTR_DATETYPE_NAME			"DT"
#define CSTR_STRINGTYPE_NAME		"ST"

#include "container.hpp"
#include "composite.hpp"

class BaseType : public Composite<BaseType> {
	string _typeId, _name, _description;
public:
	typedef SPtr::shared<BaseType> TypePtr;
	typedef std::list<string> StringList;
	BaseType(string const & name) : _name(name){}
	virtual ~BaseType(){}

	string typeId() const { return _typeId; }
	string name() const { return _name; }
	string description() const { return _description; }
	void typeId(string const & typeId){
		_typeId = typeId;
	}
	void name(string const & name){
		_name = name;
	}
	void description(string const & description){
		_description = description;
	}

	virtual void additional(const StringList & values){}
	virtual bool validate(string const & value) const = 0;

	// !!! test
	void dump(){
		std::cout << "BaseType::dump() _typeId=" << _typeId << " ,_name=" << _name << ", _description=" << _description << "\n";
	}
};

class SimpleType : public BaseType {
	EmptyContainer<BaseType> _children;
public:
	SimpleType(string const & name) : BaseType(name) {}
	ContainerBase<BaseType> & children() {
		return _children;
	}
};

class IdType : public SimpleType {
	std::set<string> _set;
public:
	IdType() : SimpleType(CSTR_IDTYPE_NAME) {}
	void additional(const StringList & values){
		//!!! insert into _set
//		_set = values;
	}
	bool validate(string const & value) const {
		return _set.find(value) != _set.end();
	}
};
class StringType : public SimpleType {
public:
	StringType() : SimpleType(CSTR_STRINGTYPE_NAME) {}
	bool validate(string const & value) const {
		return true;
	}
};
class DateType : public SimpleType {
public:
	DateType() : SimpleType(CSTR_DATETYPE_NAME) {}
	bool validate(string const & value) const {
		//!!!
		return false;
	}
};


class ComplexType : public BaseType {
	mutable Container<BaseType> _children;

public:
	ComplexType(string const & name) : BaseType(name) {}
	bool validate(string const & value) const {
		bool ret = false;
		_children.first();
		while( ! _children.isEnd() ){
//			ret
		}
		// !!!!
		return true;
	}
	ContainerBase<BaseType> & children() {
		return _children;
	}
};



#endif	//types_h
