#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
/*
template< template<typename, typename > class Cont, typename T1, typename T2>
std::ostream &operator <<(std::ostream &out, Cont<T1, T2> const &c){

	for(auto it : c){
			out << it << " ";
	}
	out << "\n";
	return out;
}
*/
//Using variadic templates
template<typename T, template<class,class...> class C, class... Args>
std::ostream& operator <<(std::ostream& os, const C<T,Args...>& objs){
	os << __PRETTY_FUNCTION__ << " \n";
	for(const auto &it : objs){
		os << it << " " ;
	}
	os << "\n";
	return os;
}


template<template<typename> class DERIVED, typename VALUE>
struct interface{
	void function(VALUE v){
		static_cast<DERIVED<VALUE> *>(this)->function(v);
	}
};

template<typename T>
struct derived : public interface<derived, T> {
	void function(T v){
		cout << " value of V is " << v << endl;
	}
};

//template<typename T, template<typename> class C>
template<template<class> class C, class T>
void print1(C<T> &c){
	typename C<T>::iterator it = c.begin();
	for(;it != c.end(); it++)
		cout << *it << " ";

	cout << endl ;
}

int main(){

	//std::vector<int> v{1,2,3,4,5};
	//std::cout << v  ;
	//derived<int> d;
	interface<derived, int> *d = new derived<int>();
	d->function(10);
	cout << endl ;
	vector<string> v(5, "Yow!");
	print1(v);
	return 0;
}
