#ifndef types_h
#define types_h

#include <string>
#include <set>
#include <list>

#include "container.hpp"
#include "composite.hpp"

using std::string;

#define CSTR_IDTYPE_NAME			"ID"
#define CSTR_DATETYPE_NAME			"DT"
#define CSTR_STRINGTYPE_NAME		"ST"

class BaseType : public Composite<BaseType> {
protected:
	string _typeId, _name, _description;
public:
	typedef Composite<BaseType>::BasePtr TypePtr;
	typedef std::list<string> StringList;
	BaseType(string const & name) : _name(name){}

	string id() const;
	string name() const;
	string description() const;
	void id(string const & typeId);
	void name(string const & name);
	void description(string const & description);
	virtual void additional(const StringList & values);
	virtual bool validate(string const & value) const = 0;

	// !!! test
	virtual void dump() = 0;
};

class SimpleType : public BaseType {
	EmptyContainer<BaseType> _children;
public:
	SimpleType(string const & name) : BaseType(name) {}
	ContainerBase<BaseType> & children();
	void dump();
};

class IdType : public SimpleType {
	std::set<string> _set;
public:
	IdType() : SimpleType(CSTR_IDTYPE_NAME) {}
	void additional(const StringList & values);
	bool validate(string const & value) const;
};

class StringType : public SimpleType {
public:
	StringType() : SimpleType(CSTR_STRINGTYPE_NAME) {}
	bool validate(string const & value) const;
};

class DateType : public SimpleType {
public:
	DateType() : SimpleType(CSTR_DATETYPE_NAME) {}
	bool validate(string const & value) const;
};

class ComplexType : public BaseType {
	mutable Container<BaseType> _children;
public:
	ComplexType(string const & name) : BaseType(name) {}
	bool validate(string const & value) const;
	ContainerBase<BaseType> & children();
	void dump();
};

#endif	//types_h
