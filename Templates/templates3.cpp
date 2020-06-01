#include<iostream>
#include <mutex>

std::mutex mtx;

using namespace std;
enum LockType{
        PROCESS_UE_INFO_LOCK,
        MDB_DIP_LOCK
};

template<LockType T>
struct Test{
	static std::mutex m;
        Test(){
		cout << "\n Aquring lock \n";
		m.lock();
		cout << "\n Aquired lock \n";
        }
        ~Test(){
		cout << "\n Releasing lock lock \n";
		m.unlock();
		cout << "\n Released lock \n";
        }
};


template<LockType T>
mutex Test<T>::m; 


void f1() {

	Test<PROCESS_UE_INFO_LOCK> o1;
	//Test<PROCESS_UE_INFO_LOCK> o2;
	//Test<PROCESS_UE_INFO_LOCK> o3;
	//Test<PROCESS_UE_INFO_LOCK> o4;
	//Test<PROCESS_UE_INFO_LOCK> o5;

	Test<MDB_DIP_LOCK> o6;
	//Test<MDB_DIP_LOCK> o7;
	//Test<MDB_DIP_LOCK> o8;
	//Test<MDB_DIP_LOCK> o9;

	//cout << "\n Counts " << o4.cnt << "\n";
	//cout << "\n Counts " << o7.cnt << "\n";
	//cout << "\n Counts " << o1.cnt << "\n";
	//cout << "\n Counts " << o9.cnt << "\n";

}

void f2(){
	std::mutex m;
	m.lock();
	cout << "Lock1 \n";

	m.lock();
	cout << "Lock2 \n";

}
int main(){


	return 0;
}
