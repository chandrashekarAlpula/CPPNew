#include<iostream>
#include<fstream>
#include<set>
#include<iterator>
#include<algorithm>

using namespace std;



class Test{
	int x,y;
public:
	Test(int a, int b) : x(a), y(b){}

	/*friend bool operator <(Test* const  &t1, Test* const  &t2) {
		return t1.x > t2.x && t1.y > t2.y;
	}*/

	bool operator <(const Test &t) const {
		cout << endl << "Hello  " << endl ;
		return x > t.x && y > t.y;
	}

	/*bool operator <(const Test &t) const {
			cout << endl << "Hello  " << endl ;
			return x > t.x && y > t.y;
		}
		*/

	friend std::ostream &operator <<(std::ostream &os, const Test &t){
		os << "X " << t.x << " Y " << t.y;
		return os;
	}
};


struct comp{
	bool operator()(const Test *a, const Test* b) const {
		cout << " HERE ";
		return *a < *b;
	}
};

int main(int argc, char *argv[]){
	std::set<Test *, comp> mySet;
	//std::set<Test *> mySet;
	for(int i = 1; i <= 20; i++)
		mySet.insert(new Test(i, i*10));

	for(auto &s1 : mySet)
		cout << *s1 << " ";

	cout << endl ;
	/*if(argc < 2 ){
		cout << endl << "less arguments" << endl ;
		return 0;
	}
	ifstream file(argv[1]);
	std::set<string> words;
	std::string word;
	while(file >> word){
		words.insert(word);
	}
	cout << endl << "Number of uniq words " << words.size() << endl;
	*/
	return 0;
}
