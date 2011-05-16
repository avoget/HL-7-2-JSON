#ifndef fields_h
#define fields_h

#include "types.hpp"

class BaseField : public Composite<BaseField> {
	BaseType & _type;
public:
	typedef Composite<BaseField>::BasePtr FieldPtr;
	typedef Composite<BaseType>::BasePtr  TypePtr;

	BaseField(BaseType &type) : _type(type) {}

	virtual string get() const = 0;
	virtual void set(string value, char sep) = 0;
	BaseType & type() const {
		return _type;
	}
	virtual FieldPtr find(TypePtr const & type) = 0;

	static FieldPtr create(TypePtr const & typesRoot);

	virtual void dump() = 0;
};

class ComplexField : public BaseField {
	Container<BaseField> _children;
	static char nextSep(char sep);
public:
	ComplexField(BaseType &type) : BaseField(type) {}

	string get() const;
	void set(string value, char sep);
	ContainerBase<BaseField> & children();
	FieldPtr find(TypePtr const & type);

	void dump();
};

class SimpleField : public BaseField {
	string _value;
	EmptyContainer<BaseField> _children;
public:
	SimpleField(BaseType &type) : BaseField(type) {}

	string get() const;
	void set(string value, char sep);
	ContainerBase<BaseField> & children();
	FieldPtr find(TypePtr const & type);

	void dump();
};

#endif	//fields_h
