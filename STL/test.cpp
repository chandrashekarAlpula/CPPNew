/*
 * test.cpp
 *
 *  Created on: Jul 30, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
using namespace std;

class X{

public:
	int z;
	X(int a = 0){
		z = a;
		cout << "In X const" << endl;
	}
	X(const X &x){
		cout << "In X copy const" << endl;
	}
};

void fun(){
	static X x(30);
	cout << endl << "In fun" << endl;
	throw &x;
}

int main(){

	try{
		fun();
	}catch(X &a){
		cout << endl << "In catch " << endl;
	}catch(X *x){
		cout << endl << "In catch ptr and z is " << x->z << endl;

	}catch(...){
		cout << endl << "In catch default" << endl;
	}
	return 0;
}



