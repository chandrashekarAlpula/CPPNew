#include<iostream>
#include<string>
using namespace std;


void print(){
	cout << " " << endl;
}

template <typename T, typename... Types>
void print(T var, Types... args){
	cout << var << endl ;
	print(args...);
}


void Print1(){
	cout << " " << endl;

}

template<typename T, typename... Types>
void Print1(T arg, Types... args){
	cout << arg << " ";
	Print1(args...);
}

int main(){

	//print(1,2,3,400,5.6,"hello", "how r u");
	Print1("Hello", "Mr", "now" ,"you","turned",37);
	return 0;
}
