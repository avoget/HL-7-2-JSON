#include <iostream>
#include "hl7types.hpp"

int main(int argc, char **argv){

	HL7::Types::Factory * fctry = HL7::Types::Factory::instance();
	fctry->load("msh", "t2.txt");
	HL7::Types::Type t = fctry->get("msh");

	t.set(0, "My full name");
	t.set(1, "Alex");
	t.set(2, "Fofanov");

	t.print(std::cout);
}

//