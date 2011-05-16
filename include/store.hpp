#ifndef TYPES_STORE_H
#define TYPES_STORE_H

#include <map>
#include <string>

template <typename TypePtr> class Store {
private:
	typedef std::map< std::string, TypePtr > tStore;
	tStore _types;
public:
	TypePtr get( std::string const & id ) const {
		typename tStore::const_iterator it = _types.find( id );
		TypePtr ret;
		if( it != _types.end() ){
			ret = it->second;
		}
		return ret;
	}
	void add(TypePtr const & val){
		TypePtr t = get(val->id());
		if( !t ){
			_types[ val->id() ] = val;
		}
	}
};


#endif	//TYPES_STORE_H
