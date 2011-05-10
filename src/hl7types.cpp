#include <algorithm>
#include <iterator>
//#include <iostream>
#include <fstream>

#include "hl7types.hpp"


namespace HL7{ namespace Types{

Description::Description(string const & name) : _name(name) {}
string Description::name(){
	return _name;
}
void Description::add(string const & descr){
	_fielDescr.push_back(descr);
}
int Description::find(string const & descr){
	std::list<string>::iterator pos = std::find(_fielDescr.begin(), _fielDescr.end(), descr);
	return pos == _fielDescr.end() ? -1 : std::distance(_fielDescr.begin(), pos);
}
string Description::get(int index){
	std::list<string>::iterator it = _fielDescr.begin();
	std::advance(it, index);
	return *it;
}
int Description::size(){
	return _fielDescr.size();
}


Type::Type(SPtr::shared<Description> descr) : _descr(descr), _values(_descr->size()) {}
int Type::size(){
	return _descr->size();
}
void Type::set(int index, string const & val){
	if(index >= 0 && index < size()){
		_values[index] = val;
	}
}
string Type::get(int index){
	return _values[index];
}
void Type::print(std::ostream & out){
	out << "Type name=" << descr()->name() << "\n";
	for (int i = 0; i < size(); ++i) {
		out << "Field descr =" << descr()->get(i) << ", value = " << get(i) << "\n";
	}
}
SPtr::shared<Description> Type::descr(){
	return _descr; 
}


Factory::Factory(){}
void Factory::load(string const & typeName, string const & fileName){
	std::fstream in(fileName.c_str());
	if (in) {
		std::istream_iterator<string> iit(in);
		std::istream_iterator<string> eos;
		if(!find(typeName).get()){
			tDescr descr = new Description(typeName);
			while(iit != eos){
				descr->add(*iit);
				iit++;
			}
			_cash[typeName] = descr;
		}
	}
}
Type Factory::get(string const & typeName){
	tDescr descr = find(typeName);
	if (!descr){
		throw "Didn`t load type";
	}
	return Type(descr);
}
Factory::tDescr Factory::find(string const &typeName){
	std::map<string, tDescr>::const_iterator it = _cash.find(typeName);
	tDescr ret;
	if (it != _cash.end()){
		ret = it->second;
	}
	return ret;
}
Factory * Factory::instance(){
	static SPtr::shared<Factory> self;
	if (!self) {
		self = new Factory();
	}
	return self.get();
}


};}; //namespace HL7 - namespace Types

