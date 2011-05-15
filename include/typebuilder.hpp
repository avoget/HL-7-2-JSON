#ifndef TYPES_BUILDER_H
#define TYPES_BUILDER_H

#include <list>
#include <fstream>
#include <iostream>

#include "factory.hpp"
#include "store.hpp"
#include "parser.hpp"


class TypeBuilder {
	TypeStore & _store;
	SimpleTypeFactory _factory;
	BaseType::TypePtr _newType;
public:
	typedef std::list<string> StringList;
	TypeBuilder(TypeStore & store) : _store(store){}

	void create(string const & typeId, string const & name, string const & description){
		std::cout << "TypeBuilder::create() typeId=" << typeId << " ,name=" << name << ", description=" << description << "\n";
		_newType = _factory.getType(name);
		_newType->typeId(typeId);
		_newType->description(description);
	}
	BaseType::TypePtr get(){
		return _newType;
	}
	void addSubType(string const & typeId){
		std::cout << "TypeBuilder::addSubType() typeId=" << typeId << "\n";
		if(!_newType->children().container()){
			//!!! need to throw
			std::cout << "Can`t add to simple type\n";
		}
		BaseType::TypePtr ft = _store.get(typeId);
		if(!ft){
			//!!! need to throw
			std::cout << "Can`t find added typeId\n";
		}
		_newType->children().add(ft);
	}
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

	void loadLine(string const & line){
		if(!line.size()) return;
		std::cout << "FileTypeDirector::loadLine() line=" << line << "\n";
		string t;
		if( line[0] != ','){
			t = ',' + line;
		}else{
			t = line;
		}		
		Parser::Parser::StringVector v = _parser.parseString(t, ',');
		Parser::Parser::StringVectorIterator it = v.begin();
		_builder.create(v[0], v[1], v[2]);
		it++;
		it++;
		it++;
		for(; it != v.end(); ++it){
			_builder.addSubType(*it);
		}
	}
public:
	FileTypeDirector(TypeStore & store) : BuildTypeDirector(store) {}
	
	void loadFile(string const & fileName){
		std::ifstream in(fileName.c_str());
		if (in) {
			string line;
			while(!getline(in, line, '\n').eof()){
				loadLine(line);
			}
		}else{
			std::cout << "Can`t open file:" << fileName << "\n";
		}
	}
	void createTypes(){
		loadFile("types.txt");
	}
};


#endif	//TYPES_BUILDER_H
