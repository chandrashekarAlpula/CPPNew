#include<iostream>
#include<map>
#include<list>
#include<utility>

using namespace std;

template<typename T1, typename T2>
class Test{
	typedef typename std::pair<T1, T2> PAIR;
	typedef typename std::map<T1, PAIR> MAP;

	MAP m;

public:
	void insert(T1 t1, T2 t2){
		m.insert(std::make_pair(t1, std::make_pair(t1,t2)));

	}
	void print(){
		typename MAP::iterator it =  m.begin();
		for(; it != m.end(); it++)
			cout << it->second.second << " ";
		cout << endl;
	}
};
int main(){


	Test<int, int> tt;

	std::list<int> ll;
	for(auto i = 0; i < 10; i++){
		ll.push_front(i);
	}
	std::list<int>::reverse_iterator ritr = ll.rbegin();
	std::list<int>::iterator itr = ll.begin();
	ll.erase(ritr--);
	//std::list<int>::iterator itr = (std::list<int>::iterator)(ritr);
	cout << endl << *itr << endl;
	printf("\n itr %u and ritr %u", itr, ritr );

	//tt.insert(2,34);
	//tt.print();



	return 0;
}

