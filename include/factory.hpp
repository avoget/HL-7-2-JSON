#ifndef TYPES_FACTORY_H
#define TYPES_FACTORY_H

#include <string>
#include "types.hpp"

class SimpleTypeFactory {
//	SimpleTypeFactory(){}
public:
	static BaseType::TypePtr getType(string const & name);
};


#endif //TYPES_FACTORY_H
