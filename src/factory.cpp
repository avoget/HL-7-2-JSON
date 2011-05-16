#include "factory.hpp"

BaseType::TypePtr SimpleTypeFactory::getType(string const & name){
	BaseType::TypePtr ret;
	if(name == CSTR_DATETYPE_NAME){
		ret = new DateType();
	}else if(name == CSTR_IDTYPE_NAME){
		ret = new IdType();
	}else	if(name == CSTR_STRINGTYPE_NAME){
		ret = new StringType();
	}else{
		ret = new ComplexType(name);
	}
	return ret;
}
