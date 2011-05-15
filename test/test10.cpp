#include <iostream>
#include "types.hpp"
#include "fields.hpp"
#include "parser.hpp"
#include "store.hpp"
#include "factory.hpp"
#include "typebuilder.hpp"

int main(){

	Parser::Parser parser;
	
	Parser::Parser::StringVector v = parser.parseString(",1,2 3,44-5 5", ',');
	std::cout << "Test 1\n";
	for(Parser::Parser::StringVectorIterator it = v.begin(); it != v.end(); ++it){
		std::cout << *it << "\n";
	}
	std::cout << "test 1 - ok\n";


	std::cout << "test 2\n";
	TypeStore store;
	std::cout << "test 2 - ok\n";

	std::cout << "test 3\n";
	SimpleTypeFactory factory;
	std::cout << "test 3 - ok\n";

	std::cout << "test 4\n";
	BaseType::TypePtr type1 = factory.getType("ID");
	type1->typeId("pd1Id");
	type1->dump();
	store.add(type1);
	store.get("pd1Id")->dump();
	std::cout << "test 4 - ok\n";

	std::cout << "test 5\n";
	FileTypeDirector fd(store);
	fd.createTypes();
	std::cout << "test 5 - ok\n";

	StringType strType;
	SimpleField strField(strType);



	
	std::cout << "ok\n";
	return 0;
}
