#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct GraphicalObject{
	virtual void draw() = 0;
};

struct Circle : GraphicalObject{
	void draw() override {
		cout << "Circle " << endl ;
	}
};

struct Square : GraphicalObject{
	void draw() override{
		cout << __PRETTY_FUNCTION__ << " :: Square " << endl ;
	}
};

struct GroupObject : GraphicalObject{
	std::string name;
	std::vector<GraphicalObject*> grp;
	GroupObject(string name) : name{name}{}

	void draw() override {
		cout <<"Group Oject " << name << " contains " << endl;
		for(auto &&obj : grp)
			obj->draw();
	}
};
int main(){
	Circle c1,c2;
	GroupObject g1("sub Group");
	g1.grp.push_back(&c1);
	g1.grp.push_back(&c2);

	Square s1;
	GroupObject g2{"Root"};
	g2.grp.push_back(&g1);
	g2.grp.push_back(&s1);

	g2.draw();
	return 0;
}
