#ifndef composite_h
#define composite_h

#include "container.hpp"

template <typename T> class Composite{
public:
	virtual ~Composite(){}
	virtual ContainerBase<T> & children() = 0;
};


#endif	//composite_h
