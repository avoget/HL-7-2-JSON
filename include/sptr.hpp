#pragma once

#include <cstdlib>
#include <new>

namespace SPtr{
	// Simple non thread-safe shared_ptr
	template <typename T>
	class shared{
	public:
		typedef void(*tdeleter)(T*);
		static void deleter(T *ptr){
			delete ptr;
		}
		typedef shared<T> self;
		shared() : intrnl(NULL), _deleter(&deleter) {}
		shared(T * ptr, tdeleter adeleter = &deleter) : intrnl(NULL), _deleter(adeleter) {
			operator=(ptr);
		}
		shared(const shared &r) : intrnl(NULL){
			operator=(r);
		}
		template<typename O>
		shared(const shared<O> &r) : intrnl(NULL){
			operator=<O>(r);
		}
		T& operator*() const throw(){
			return *operator->();
		}
		T* operator->() const throw(){
			if(intrnl){
				return intrnl->ptr;
			}else{
				return NULL;
			}
		}
		T* get() const throw(){
			return operator->();
		}
		self& operator=(const shared &r){
			if(this != &r){
				clear();
				intrnl = r.intrnl;
				if(intrnl)
					intrnl->inc();
			}
			return *this;
		}
		template<typename O>
		self& operator=(const shared<O> &r){
			if((void*)this->intrnl != (void*)r.intrnl){
				clear();
				intrnl = (self::Internal*)r.intrnl;
				if(intrnl)
					intrnl->inc();
			}
			return *this;
		}
		self& operator=(T *ptr){
			clear();
			if(ptr){
				intrnl = new(std::nothrow) Internal(ptr, _deleter);
			}
			return *this;
		}
		operator bool() const{
			return get();
		}		
		~shared(){
			clear();
		}
	private:
		template<typename O> friend class shared;
		void clear(){
			if(intrnl){
				intrnl->dec();
				if(intrnl->cnt == 0){
					delete intrnl;			intrnl = NULL;
				}
			}
		}
		struct Internal{
			T *ptr;
			tdeleter _deleter;
			int cnt;
			Internal(T * ptr, tdeleter adeleter = &deleter) : ptr(ptr), cnt(ptr ? 1 : 0), _deleter(adeleter) {}
			~Internal(){
				(*_deleter)(ptr);
				ptr = NULL;
			}
			void inc(){
				cnt++;
			}
			void dec(){
				cnt--;
			}
		};
		Internal *intrnl;
		tdeleter _deleter;
	};
};		//namespace SPtr

//
