/*
 * Set1.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<set>
#include<vector>

using namespace std;

void f1(){
	int arr[] = {2,3,17,33,45,77};
	std::set<int> st(std::begin(arr), std::end(arr));
	for(const auto &elem : st){
		cout << elem << " ";
	}
	cout << endl;

	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	std::set<int>  st1(v.begin(), v.end());

	for(const auto &elem : st1){
		cout << elem << "\t";
	}
	cout << endl;
	std::set<int>  st2;
	cout << "Max Size " << st2.max_size();
	set<int>::pointer = st1.begin();
}

int main(){

	f1();
	return 0;
}



