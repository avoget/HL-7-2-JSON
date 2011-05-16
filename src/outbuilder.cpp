#include <fstream>
#include <iostream>

#include "outbuilder.hpp"

void OutBuilder::create(string const & id, string const & type, string const & title, string const & types){
	std::cout << "OutBuilder::create() id=" << id << " ,type=" << type << ", title=" << title << ", types=" << types<< "\n";
	if(type == "S"){
		_newOut = new SimpleOut(title);
	}else{
		_newOut = new ComplexOut(title);
	}
	_newOut->id(id);
	Parser::Parser parser;
	Parser::Parser::StringVector v = parser.parseString(types, ':');
	Parser::Parser::StringVectorIterator it = v.begin();
	for(; it != v.end(); ++it){
		BaseType::TypePtr type = _typeStore.get(*it);
		_newOut->addType(type);
	}
std::cout << "OutBuilder::create() end\n";
}
BaseOut::TypePtr OutBuilder::get() const {
	return _newOut;
}
void OutBuilder::addSubOut(string const & id){
//	std::cout << "OutBuilder::addSubOut() typeId=" << typeId << "\n";
	if(!_newOut->children().container()){
		//!!! need to throw
		std::cout << "Can`t add to simple type\n";
	}
	BaseOut::TypePtr ft = _store.get( id );
	if(!ft){
		//!!! need to throw
		std::cout << "Can`t find added typeId\n";
	}
	_newOut->children().add(ft);
}
void OutBuilder::add2Store(BaseOut::TypePtr const & val){
	_store.add(val);
}

//=================== FileTypeDirector

void FileOutDirector::loadLine(string const & line){
	if(!line.size()) return;
	std::cout << "FileOutDirector::loadLine() line=" << line << "\n";
	string t;
	if( line[0] != ','){
		t = ',' + line;
	}else{
		t = line;
	}
	Parser::Parser::StringVector v = _parser.parseString(t, ',');
	Parser::Parser::StringVectorIterator it = v.begin();
	_builder.create(v[0], v[1], v[2], v[3]);
	it++;
	it++;
	it++;
	it++;
	for(; it != v.end(); ++it){
		_builder.addSubOut(*it);
	}
	_builder.add2Store(_builder.get());
//	std::cout << "FileOutDirector::loadLine() end\n";
}
void FileOutDirector::loadFile(string const & fileName){
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
void FileOutDirector::create(){
	loadFile("outs.txt");
}

//
