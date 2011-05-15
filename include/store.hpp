#ifndef TYPES_STORE_H
#define TYPES_STORE_H

#include <map>
#include "types.hpp"

class TypeStore {
	typedef std::map<string, BaseType::TypePtr> tStore;
	tStore _types;
public:
	BaseType::TypePtr get(string const &typeId){
		tStore::const_iterator it = _types.find(typeId);
		BaseType::TypePtr ret;
		if (it != _types.end()){
			ret = it->second;
		}
		return ret;
	}
	void add(BaseType::TypePtr const & type){
//std::cout << "TypeStore::add()\n";
//type->dump();
		_types[type->typeId()] = type;
	}
};


#endif	//TYPES_STORE_H
