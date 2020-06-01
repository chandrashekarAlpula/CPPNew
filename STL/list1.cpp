#include<iostream>
#include<list>
#include<set>
#include<algorithm>
#include <iterator>

using namespace std;
int main(){

	std::list<int> l;
	std::list<int>::iterator itt[10];
	for(int i = 0; i < 10; i++){
		l.push_back(i);
		itt[i] = --(l.end());
	}

	std::list<int>::iterator itt1 = l.begin();
	itt1++;itt1++;
	l.insert(itt1,345);

	for(int i = 0; i < 10; i++){
		cout << endl << *itt[i] ;
	}

	cout << endl << "list elements " << endl ;
	for(auto &item : l)
		cout << item << " ";
	cout << endl ;

/*
	std::list<int> l1{1,2,3,4,5,6};
	std::list<int>::iterator it = l1.begin();
	it++;
	it++;
	cout << endl << "It is " << *it << endl ;
	std::list<int>::iterator it2 = l1.begin();
	it2++;it2++;it2++;it2++;it2++;

	l1.insert(it, 20);
	l1.insert(it2, 57);
	for(auto &item : l1)
		cout << item << " ";
	cout << endl ;
	l1.erase(it);
	for(auto &item : l1)
		cout << item << " ";
	cout << endl ;
	*/
	//ostream_iterator<int> oitr(cout,"\t");
	//std::copy(l1.begin(), l1.end(), ostream_iterator<int>(cout,"\n"));
	//std::copy(l1.begin(), l1.end(), oitr);
	return 0;
}
