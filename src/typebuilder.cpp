#include <fstream>
#include <iostream>

#include "typebuilder.hpp"

void TypeBuilder::create(string const & typeId, string const & name, string const & description){
//	std::cout << "TypeBuilder::create() typeId=" << typeId << " ,name=" << name << ", description=" << description << "\n";
	_newType = _factory.getType(name);
	_newType->id(typeId);
	_newType->description(description);

	_newType->dump();
//	std::cout << "TypeBuilder::create() end\n";
}
BaseType::TypePtr TypeBuilder::get() const {
	return _newType;
}
void TypeBuilder::addSubType(string const & typeId){
//	std::cout << "TypeBuilder::addSubType() typeId=" << typeId << "\n";
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
void TypeBuilder::add2Store(BaseType::TypePtr const & type){
	_store.add(type);
}

//=================== FileTypeDirector

void FileTypeDirector::loadLine(string const & line){
	if(!line.size()) return;
//	std::cout << "FileTypeDirector::loadLine() line=" << line << "\n";
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
	_builder.add2Store(_builder.get());
//	std::cout << "FileTypeDirector::loadLine() end\n";
}
void FileTypeDirector::loadFile(string const & fileName){
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
void FileTypeDirector::createTypes(){
	loadFile("types.txt");
}

//
