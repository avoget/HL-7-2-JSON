#ifndef parser_h
#define parser_h

#include <vector>
#include <string>
namespace Parser{

class Parser{
	std::vector<std::string> _values;
	void clear();
public:
	typedef std::vector<std::string> StringVector;
	typedef std::vector<std::string>::iterator StringVectorIterator;
	StringVector & parseString(std::string const & str, char sep);

};

}; // namespace Parser

#endif	//parser_h
