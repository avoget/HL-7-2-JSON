#ifndef types_h
#define types_h

#include <string>
#include <set>
#include <list>
using std::string;

#include "container.hpp"
#include "composite.hpp"

class BaseType : public Composite<BaseType> {
	string _typeId, _name, _description;
public:
	typedef std::list<string> StringList;
	BaseType(string const & name) : _name(name){}
	virtual ~BaseType(){}

	string & typeId(){ return _typeId; }
	string & name(){ return _name; }
	string & description(){	return _description; }
	string const & typeId() const { return _typeId; }
	string const & name() const { return _name; }
	string const & description() const {	return _description; }

	virtual void additional(const StringList & values){}
	virtual bool validate(string const & value) const = 0;
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
	std::set<string> _table;
public:
	IdType(string const & name) : SimpleType(name) {}
	void additional(const StringList & values){}
	bool validate(string const & value) const {
		return _table.find(value) != _table.end();
	}
};
class StringType : public SimpleType {
public:
	StringType(string const & name) : SimpleType(name) {}
	bool validate(string const & value) const {
		return true;
	}
};
class DateType : public SimpleType {
public:
	DateType(string const & name) : SimpleType(name) {}
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
