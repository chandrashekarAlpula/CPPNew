#include<iostream>
#include<vector>

using namespace std;

template<typename CONT, typename CLASS, typename RET>
void apply(CONT &container, RET (CLASS::*fun)()){ // with function ptr with no arguments
	typename CONT::iterator it = container.begin();
	while(it != container.end()){
		((*it)->*fun)();
		it++;
	}
}


template<typename CONT, typename CLASS,  typename ARG1, typename RET>
void apply(CONT &container, RET (CLASS::*fun)(ARG1), ARG1 arg1){ // with function ptr with 1 arguments
	typename CONT::iterator it = container.begin();
	while(it != container.end()){
		((*it)->*fun)(arg1);
		it++;
	}
}

template<typename CONT, typename CLASS, typename RET, typename ARG1, typename ARG2>
void apply(CONT &container, RET (CLASS::*fun)(ARG1, ARG2), ARG1 arg1, ARG2 arg2){ // with function ptr with 1 arguments
	typename CONT::iterator it = container.begin();
	while(it != container.end()){
		((*it)->*fun)(arg1, arg2);
		it++;
	}
}
class TEST{
public:
	virtual void speak(int){
		cout << endl << "Speak\n";
	}

	virtual void eat(int,char){
		cout << endl << "Eat\n";
	}
	virtual void sit(){
		cout << endl << "Sit\n";
	}
};

class TEST1 : public TEST{
public:
	void speak(int){
		cout << endl << "Speak1\n";
	}

	void eat(int,char){
		cout << endl << "Eat1\n";
	}
	void sit(){
		cout << endl << "Sit1\n";
	}
};
int main(){

	vector<TEST *> tests{new TEST(), new TEST1(), new TEST()};
	cout << "\n size of vector " << tests.size() << endl ;
	apply(tests, &TEST::speak, 1);
	//apply(tests, &TEST::eat,  1, 'z');
	//apply(tests, &TEST::sit);
	return 0;
}
