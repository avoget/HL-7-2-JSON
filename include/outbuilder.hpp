#ifndef OUT_BUILDER_H
#define OUT_BUILDER_H

#include "store.hpp"
#include "parser.hpp"
#include "out.hpp"

typedef Store<BaseOut::TypePtr>  OutStore;
typedef Store<BaseType::TypePtr> TypeStore;

class OutBuilder {
	OutStore & _store;
	TypeStore & _typeStore;
	BaseOut::TypePtr _newOut;
public:
	OutBuilder(OutStore & store, TypeStore & typeStore) : _store(store), _typeStore(typeStore) {}

	void create(string const & id, string const & type, string const & title, string const & types);

	BaseOut::TypePtr get() const;
	void addSubOut(string const & id);
	void add2Store(BaseOut::TypePtr const & val);
};

class BuildOutDirector {
protected:
	OutBuilder _builder;
public:
	BuildOutDirector( OutStore & store, TypeStore & typeStore) : _builder(store, typeStore) {}
	virtual ~BuildOutDirector(){}

	virtual void create() = 0;
};

class FileOutDirector : public BuildOutDirector {
	Parser::Parser _parser;

	void loadLine(string const & line);
public:
	FileOutDirector(OutStore & store, TypeStore & typeStore) : BuildOutDirector(store, typeStore) {}

	void loadFile(string const & fileName);
	void create();
};


#endif	//OUT_BUILDER_H
