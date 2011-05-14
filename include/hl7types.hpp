#ifndef hl7types_h
#define hl7types_h

#include <string>
#include <list>
#include <map>
#include <ostream>
#include <vector>

#include "sptr.hpp"

using std::string;

namespace HL7{ namespace Types{

struct Description{
	Description(string const & name);

	string name();
	void   add(string const & descr);
	int    find(string const & descr);
	string get(int index);
	int    size();
private:
	std::list<string> _fielDescr;
	string _name;
};

class Factory;

struct Type {
	string name();

	int    size();
	void   set(int index, string const & val);
	string get(int index);
	void   load(string const &val);

	void print(std::ostream & out);
private:
	friend class Factory;
	Type(SPtr::shared<Description> descr);
	
	SPtr::shared<Description> descr();
	SPtr::shared<Description> _descr;
	std::vector<string> _values;
};


struct Factory{
	void load(string const & typeName, string const & fileName);

	Type get(string const & typeName);

	static Factory * instance();

private:
	typedef SPtr::shared<Description> tDescr;
	tDescr find(string const &typeName);
	Factory();
	std::map<string, tDescr> _cash;
};



};}; //namespace HL7 - namespace Types


#endif	//hl7types_h
