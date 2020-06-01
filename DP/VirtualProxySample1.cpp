#include<iostream>
#include<string>

using namespace std;

struct image{
	virtual void draw() = 0;
};

struct BitMap : public image{
	BitMap(std::string filename) : filename(filename){
		cout << "\n Loading file " << filename << endl;
	}
	void draw() override {
		cout << "\n Drwaing bitmap " << endl;
	}
private:
	std::string filename;
};

struct LazyBitMap : image{
	LazyBitMap(std::string filename) : filename(filename){
		cout << endl <<"INit lazy bit map\n";
	}
	void draw(){
		cout << endl <<"Drawing lazy bit map\n";
		if(bitPtr == nullptr){
			bitPtr = new BitMap(filename);
			bitPtr->draw();
		}
	}
private :
	std::string filename;
	BitMap *bitPtr{nullptr};
};
int main(){
	LazyBitMap b("hellow.img");
	b.draw();
	return 0;
}
