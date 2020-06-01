/*
 * template1.cpp
 *
 *  Created on: Jul 8, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>

using namespace std;


template<class T>
class T1{
private:
	static int x;
public:
	static void Incr(){
		x++;
	}
	static int Get(){
		return x;
	}
};

template<class T>
int T1<T>::x = 0;

class A : public T1<A>{
public:
	A(){
		Incr();
	}
	int Incr(){
		T1<A>::Incr();
	}
	int GetX(){
		return Get();
	}
};

class B : public T1<B>{
public:
	B(){
		Incr();
	}
	int Incr(){
		T1<B>::Incr();
	}
	int GetX(){
		return Get();
	}
};

int main(){
	A a;
	B b;
	cout << endl << a.GetX() << endl ;
	cout << endl << b.GetX() << endl ;
	a.Incr();
	b.Incr();
	a.Incr();
	cout << endl << a.GetX() << endl ;
	cout << endl << b.GetX() << endl ;
	//b.GetX();
	return 0;
}



