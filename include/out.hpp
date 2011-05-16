#ifndef TYPES_OUT_H
#define TYPES_OUT_H

#include <string>
#include <list>
#include <istream>

#include "container.hpp"
#include "composite.hpp"
#include "types.hpp"
#include "fields.hpp"

using std::string;
using std::ostream;

class BaseOut : public Composite<BaseOut> {
protected:
	typedef std::list< BaseType::TypePtr > TypeList;
	TypeList _types;
	string _title, _id;
	void printFields(ostream & out, BaseField::FieldPtr & fieldsRoot);
public:
	typedef Composite<BaseOut>::BasePtr TypePtr;

	BaseOut(string const & title) : _title(title) {}

	virtual void print(ostream & out, BaseField::FieldPtr & fieldsRoot) = 0;

	string title() const { return _title; }
	void title(string const & title) { _title = title;}

	string id() const { return _id; }
	void id(string const & aid) { _id = aid; }

	void addType(BaseType::TypePtr const & type);
};

class ComplexOut : public BaseOut {
	Container<BaseOut> _children;
public:
	ComplexOut(string const & title) : BaseOut(title) {}

	void print(ostream & out, BaseField::FieldPtr & fieldsRoot);
	ContainerBase<BaseOut> & children();
};


class SimpleOut : public BaseOut {
	EmptyContainer<BaseOut> _children;
public:
	SimpleOut(string const & title) : BaseOut(title) {}

	void print(ostream & out, BaseField::FieldPtr & fieldsRoot);
	ContainerBase<BaseOut> & children();
};

#endif	//TYPES_OUT_H
