#include<string>
#include<iostream>

using namespace std;

string trimTag(const string &text, const string &pattern1 , const string &pattern2){
	int st = text.find_first_of(pattern1);
	int ed = text.find_last_of(pattern2);

	if(st != std::string::npos)
		st++;
	if(ed != std::string::npos)
		ed--;
	return string(text.substr(st, ed -st + 1));
}
void f1(){
	string text = "<h1>This is a Header one </h1>";
	string filterText = trimTag(text, ">" , "<");
	cout << "Origin string " << text << "\nFiltered string " << filterText << endl;

}

int main(){

	f1();
	return 0;
}

