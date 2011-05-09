
#include "conv.hpp"
#include <fstream>
#include <iterator>

int main(int argc, char **argv){
	string filename;
	if (argc > 1){
		filename = argv[1];
	}else{
		std::cerr << "Error: No input file provided." << std::endl;
		return 1;
	}
	std::ifstream in(filename.c_str(), std::ios_base::in);

	if (!in){
		std::cerr << "Error: Could not open input file: " << filename << std::endl;
		return 1;
	}

	std::string storage;
	in.unsetf(std::ios::skipws);
	std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(), std::back_inserter(storage));

	std::cout << "storage=" << storage << "\n";

	HL7::Converter conv;
	conv.Input(storage);
	try{
		ADTmsg msg = conv.Convert();
		std::cout << "Parsing succeeded\n";
		msg.print();
		return 0;
	}catch(...){
		std::cout << "Parsing failed --- \n";
		return 1;
	}
}

//