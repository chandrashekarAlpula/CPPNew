#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

struct HTMLElement{
	string name, text;
	vector<HTMLElement> elements;
	int indent_size;
	HTMLElement(int zindent_size = 2): indent_size(zindent_size){}
	HTMLElement(const string &zname, const string &ztext, int zindent_size = 2) : name(zname), text(ztext), indent_size(zindent_size){}
	~HTMLElement(){

	}

	std::string str(int indent_level = 0){
		stringstream oss;
		oss << string((indent_level) * indent_size , ' ');
		oss << "<" << name << ">" << "\n";
		if(!text.empty()){
			oss << string((indent_level+1) * indent_size , ' ');
			oss << text << "\n";
		}
		for(auto elem : elements){
			oss << elem.str(indent_level + 1);
		}
		oss << string((indent_level) * indent_size , ' ');
		oss << "<" << name << "/>" << "\n";
		return oss.str();
	}
};

struct HTMLBuilder{
	HTMLElement root;
	HTMLBuilder(const string &zname) {
		root.name = zname;
	}
	void AddChild(const string &zname, const string &ztext){
		HTMLElement e(zname, ztext);
		root.elements.emplace_back(e);
	}
	string str(){
		return root.str();
	}
};

int main(){
	HTMLBuilder body("body");
	HTMLBuilder hb("ul");

	hb.AddChild("li","Name");
	hb.AddChild("li","Age");
	cout << endl << hb.str() << endl;
	return 0;
}
