#include<iostream>
using namespace std;

template<typename T> struct Property{
	T value;
	Property(T value){
		cout << "Ctor \n";
		//*this = value;
		this->value = value;
	}
	T operator=(T new_value){
		cout << "Assign " << new_value << " \n";
		return value = new_value;
	}
	operator T(){
		cout << "Get \n";
		return value;
	}
};

struct Creature{
	Property<int> strength{10};
	Property<int> agility{5};
};

int main(){

	Creature s;
	cout << endl << "Assiginig \n";
	s.strength = 80;
	//int x  = s.agility;

	cout << endl << "s.agility " << s.agility << ", s.strength " << s.strength<< "\n";
	return 0;
}



