#include <iostream>
#include "types.hpp"
#include "fields.hpp"
#include "parser.hpp"
#include "store.hpp"
#include "factory.hpp"
#include "typebuilder.hpp"
#include "outbuilder.hpp"

int main(){
	Parser::Parser parser;

	Parser::Parser::StringVector v = parser.parseString(",1,2 3,44-5 5", ',');
	std::cout << "Test 1\n";
	for(Parser::Parser::StringVectorIterator it = v.begin(); it != v.end(); ++it){
		std::cout << *it << "\n";
	}
	std::cout << "test 1 - ok\n";


	std::cout << "test 2\n";
	Store<BaseType::TypePtr> store;
	std::cout << "test 2 - ok\n";

	std::cout << "test 3\n";
	BaseType::TypePtr type1 = SimpleTypeFactory::getType("ID");
	std::cout << "test 3 - ok\n";

	std::cout << "test 4\n";
	type1->id("pd1Id");
	type1->dump();
	std::cout << "test 4 - ok\n";

	std::cout << "test 5\n";
	store.add(type1);
	store.get("pd1Id")->dump();
	std::cout << "test 5 - ok\n";

	std::cout << "test 6\n";
	FileTypeDirector fd(store);
	fd.createTypes();
	std::cout << "test 6 - ok\n";

	std::cout << "test 7\n";
	BaseType::TypePtr rootType = store.get("cid11");
	BaseField::FieldPtr rootField = BaseField::create(rootType);
	rootField->dump();
	std::cout << "test 7 - ok\n";

	std::cout << "test 8\n";
	rootType->dump();
	std::cout << "test 8 - ok\n";

	std::cout << "test 9\n";
	rootField->set("123|456", '|');
	std::cout << "test 9 - ok\n";

	std::cout << "test 10\n";
	rootField->dump();
	std::cout << "test 10 - ok\n";

	std::cout << "test 11\n";
	Store<BaseOut::TypePtr> outStore;
	FileOutDirector fod(outStore, store);
	fod.create();
	std::cout << "test 11 - ok\n";

	std::cout << "ok\n";
	return 0;
}
