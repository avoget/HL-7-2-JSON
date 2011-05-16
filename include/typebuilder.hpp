#ifndef TYPES_BUILDER_H
#define TYPES_BUILDER_H

#include "factory.hpp"
#include "store.hpp"
#include "parser.hpp"

typedef Store<BaseType::TypePtr> TypeStore;

class TypeBuilder {
	TypeStore & _store;
	SimpleTypeFactory _factory;
	BaseType::TypePtr _newType;
public:
	TypeBuilder(TypeStore & store) : _store(store){}

	void create(string const & typeId, string const & name, string const & description);
	BaseType::TypePtr get() const;
	void addSubType(string const & typeId);
	void add2Store(BaseType::TypePtr const & type);
};

class BuildTypeDirector {
protected:
	TypeBuilder _builder;
public:
	BuildTypeDirector(TypeStore & store) : _builder(store) {}
	virtual void createTypes() = 0;
	virtual ~BuildTypeDirector(){}
};

class FileTypeDirector : public BuildTypeDirector {
	Parser::Parser _parser;

	void loadLine(string const & line);
public:
	FileTypeDirector(TypeStore & store) : BuildTypeDirector(store) {}

	void loadFile(string const & fileName);
	void createTypes();
};


#endif	//TYPES_BUILDER_H
