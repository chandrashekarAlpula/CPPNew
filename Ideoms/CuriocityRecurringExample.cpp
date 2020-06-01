/*
 * t5.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: chandra.shekhar
 */


#include<iostream>
#include<memory>

using namespace std;

template<typename T>
class Base{
public:
	Base(){
		cout << endl << "In Base Const" << endl;
	}
	~Base(){
		cout << endl << "In Base Dist" << endl;
	}
	void Fun(){
		cout << endl << "In Base Fun" << endl;
		static_cast<T *>(this)->Fun();
	}
};

class D1: public Base<D1>{
public:
	D1(){
		cout << endl << "In D1 Const" << endl;
	}
	~D1(){
		cout << endl << "In D1 Dist" << endl;
	}
	void Fun(){
		cout << endl << "In D1 Fun" << endl;
	}

};
template<typename T>
void Driver(Base<T> *p){
	p->Fun();
}
int t5(){

	//Base<D1> *p = new D1();
	Driver(new D1());

	return 0;
}

