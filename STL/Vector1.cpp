/*
 * Vector1.cpp
 *
 *  Created on: Aug 6, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
using namespace std;

struct Test{
public:
	static int cnt;
	int x;
	Test(int i  = 0) : x(i){
		cnt++;
		cout << "In Con " << cnt << " x is " << x << endl;
	}
	Test(const Test &o){
		cnt++;
		x = o.x;
		cout << "In Copy Con " << cnt << " x is " << x  << endl;

	}
	~Test(){
		cnt--;
		cout << "In Dis " << cnt  << " x is " << x  << endl;
	}
};
int Test::cnt = 0;
void Print(std::vector<int> &v){
	std::vector<int>::iterator it = v.begin();
		for(; it != v.end(); it++)
			cout << *it <<  " ";
		cout << endl;

}
int main(int argv, char *argc[]){


	int size  = 10;
	std::vector<Test *> vec;
	//Test tt;
	for(int i = 0;i < size; i++){
		cout << "Adding x  " << i << endl;
		Test t(i);
		vec.push_back(&t);
	}

	cout << endl << "CNt " << Test::cnt << endl;
	/*int a[]{1,2,3,4,5,6,7};
	int aSize = sizeof(a)/sizeof(int);

	std::vector<int> v1;
	v1.assign(a,  a+aSize);
	Print(v1);
	std::vector<int> v2(v1);
	Print(v2);

	std::vector<int>::iterator it = v2.begin();
	std::vector<int> v3(v2);
	v3.assign(it, it+4);
	Print(v3);
	v1.swap(v3);
	Print(v1);
	Print(v3);
	*/

	return 0;
}



