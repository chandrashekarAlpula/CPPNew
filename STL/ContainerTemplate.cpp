/*
 * ContainerTemplate.cpp
 *
 *  Created on: Jul 30, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

class X{
	int a;
public:
	X(int x = 0) : a(x){}
	void Z(){
		//cout << endl << "In Z, value is " << a  << endl;
		a += 100;
	}
	friend std::ostream &operator <<(std::ostream &out , const X &obj){
		out << obj. a << " ";
		return out;
	}
};

template<typename Cont, typename ptr>
void fun(Cont &container, ptr p){
	typename Cont::iterator it = container.begin();
	while(it != container.end()){
		((*it).*p)();
		//(*it).Z();
		//or
		//(it->*p)(); // this is throwing compilation error
		it++;
	}
}
int main(int argv , char *argc[]){

	std::vector<X> v;
	for(auto i = 0; i < 5; i++)
		v.push_back(X(i));

	std::ostream_iterator<X> out(std::cout, " ");
	copy(v.begin(), v.end(), out);
	fun(v, &X::Z);
	cout << endl;
	copy(v.begin(), v.end(), out);
	return 0;
}



