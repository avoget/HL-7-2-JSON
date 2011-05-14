#ifndef container_h
#define container_h

#include <list>
#include "sptr.hpp"

template <typename T> class ContainerBase{
public:
	typedef SPtr::shared<T> BasePtr;
	virtual void add(const BasePtr & type){}
	virtual void first(){}
	virtual void next(){}
	virtual bool isEnd(){
		return true;
	}
	virtual BasePtr get(){
		return BasePtr();
	}
	virtual bool isEmpty(){
		return true;
	}
};

template <typename T> class Container : public ContainerBase<T> {
	typedef std::list<typename ContainerBase<T>::BasePtr> tCont;
	tCont _list;
	typename tCont::iterator it;

public:
	typedef SPtr::shared<T> BasePtr;
	void add(const BasePtr & type){
		_list.push_back(type);
	}
	void first(){
		it = _list.begin();
	}
	void next(){
		++it;
	}
	bool isEnd(){
		return it == _list.end();
	}
	BasePtr get(){
		return *it;
	}
	bool isEmpty(){
		return _list.size() == 0;
	}
};
template <typename T> class EmptyContainer : public ContainerBase<T> {
};



#endif	//container_h
