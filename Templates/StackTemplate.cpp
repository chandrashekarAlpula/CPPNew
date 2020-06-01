/*
 * StackTemplate.cpp
 *
 *  Created on: Jul 12, 2019
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Stack{
private :
	std::vector<T> stack;

public:
	void Push(const T& data);
	void Pop();
	T Top();
	void Print(){
		cout << endl;
		for(typename std::vector<T>::iterator itr = stack.begin(); itr != stack.end(); itr++)
			cout << *itr << " ";

		cout << endl;
	}
	int size();
	void clear();
};

template<typename T>
void Stack<T>::Push(const T& data){
	stack.push_back(data);
}

template<typename T>
void Stack<T>::Pop(){
	if(stack.empty()){
		throw(std::out_of_range("Stack is empty"));
	}
	stack.pop_back();
}
template<typename T>
T Stack<T>::Top(){
	if(stack.empty()){
		throw(std::out_of_range("Stack is empty"));
	}
}

template<typename T>
int Stack<T>::size(){
	return stack.size();
}

template<typename T>
void Stack<T>::clear(){
	stack.clear();
}

int main(){

	try{
		Stack<int> st;
		st.Push(20);
		st.Push(14);

		st.Print();
		st.Pop();
		st.Pop();
		st.Pop();

	}catch(std::exception const &e){
		cerr << endl << "Exception : " << e.what() << endl ;
	}
	return 0;
}


