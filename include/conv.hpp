#ifndef hl7conv_h
#define hl7conv_h

#include <string>
#include "hl7msg.hpp"

namespace HL7{

class Converter{
	public:
		void Input(std::string const & in) throw();
		ADTmsg Convert() throw(const char*);
	private:
		std::string input;
};

};
#endif	//hl7conv_h
