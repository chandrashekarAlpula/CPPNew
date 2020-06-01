//: C03:TemplateTemplate.cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
// As long as things are simple,
// this approach works fine:
template<typename C>
void print1(C& c) {
typename C::iterator it;
for(it = c.begin(); it != c.end(); it++)
cout << *it << " ";
cout << endl;
}
// Template-template argument must
// be a class; cannot use typename:
template<template<class> class C, class T>
void print2(C<T>& c) {
	copy(c.begin(), c.end(),
			ostream_iterator<T>(cout, " "));
	cout << endl;
}
*/
void Test1(){
	vector<string> v(5, "Yow!");
		//print1(v);
		//print2(v);
}

void Test2(){

	std::vector<int> vi{1,2,3,4,5};
	std::vector<int> vi2;
	std::vector<double> vd;
	vi2 = vi;
	vi.push_back(10);
	cout << "size of Vi " << vi.size() << " size of vi2 " << vi2.size() << endl;
}
int main() {
	Test2();
} ///:~
