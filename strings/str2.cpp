#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void f1(){


	char b[] = "All's well that ends well";
	string s0(b);
	cout << endl << "string is " <<  s0 << endl;

	string s1(b, 3);
	cout << endl << "string is " <<  s1 << endl;

	string s2(b +7, b+15);
	cout << endl << "string is " <<  s2 << endl;

	string s3;
	s3 = " is well " + s1 ;
	string s4 = s2 + s1 ;
	cout << endl << "string is " <<  s3 << endl;

	string s5;
	//getline(cin, s5);

	//getline(cin, s5, ':');
	//cout << "String from console " << s5 << endl ;


	string s6 = "cobra";
	int x = s6.find_first_of("hark");
	cout << "first of  found is " << x << endl;

	int x2 = s6.find_last_of("hark");
	cout << "first of  found is " << x2 << endl;

	cout << "npos " << string::npos << endl;
	s6.reserve(50);
	s6 += "123";
	cout << "String capacity is " << s6.capacity() << endl;


}

void f2(){

	std::string s("1 2 3 4 5 6");
	s.reserve(30);
	cout << "S " << s << endl;
	cout << "S Capacity " << s.capacity() << " and size "<< s.size() <<  endl;
	s.insert(1," 100 200 ");
	s.append(" 7 8 9");

	cout << "S " << s << endl;
	cout << "S Capacity " << s.capacity() << " and size "<< s.length() <<  endl;

}

void f3(){
//Replace
	string s = "A piece of text";
	string tag = "$tag$";
	s.insert(8, tag + ' ');
	cout << s << endl;

	string tag1 ="tab";
	int start = s.find(tag, 8);
	if(start != string::npos)
		s.replace(start, tag.size(), tag1);
	cout << "start " << start << endl;
	cout << s << endl;

	string s2 ="0123456";
	s2.replace(4,6,"111111");
	cout<< "S2 string :: " << s2 << endl;
}

void f4(){
	//STL replace
	std::string s = "aaaXXXXXbbbbXXXXXcccXddddYYYY";
	cout << s << endl;
	std::replace(s.begin(), s.end(), 'X', 'Y');
	cout << s << endl;
}

void f5(){
	string s(10,'S');
	s.replace(5,5,"NNNNN");
	cout << "String is " << s << endl;


}

void f6(){

	string str = "Welcome to the programming world";  
	cout<< "String contains : "<< str <<'\n';  
	//cout<<"Now, start the search from the second position and we find the first occurrence of the 'programming' is :"<<str.find_first_of("programming",2); 
	cout<<"Now, start the search from the second position and we find the first occurrence of the 'programming' is :"<<str.find_first_of("programming"); 


	std::string s ("It replaces the vowels in this sentence by asterisks.");
	std::string p("aeiou");

	cout << "\nstring " << s << endl;
	size_t found = s.find_first_of(p);
	//size_t found = s.find_first_not_of(p);
	//cout <<"Found not of " << found << endl;

	while(found != std::string::npos){
		s[found] = '*';
		found = s.find_first_of(p);
		//found = s.find_first_not_of(p);
	}
	cout << "String after replacing \n" << s << endl;

}

void f7(){
	//rfind
 	string s = "string.;a;is;This";
	std::size_t len = s.size();
	cout << "String is " << s << " and length is " << len << endl;
	std::size_t current = s.rfind(";");
	//cout << "index " << current << endl;
	std::size_t last = len -1;


	std::vector<string> v;
	while(current != std::string::npos){
		
		v.push_back(s.substr(current+1, last - current));
		current--;
		last = current;
		current = s.rfind(";", current);
	}
	
	cout << "Last is " << last << endl ;
	v.push_back(s.substr(0, last - current));
	
	for(auto & elem : v)
		cout << elem << " " ;
	cout << endl;
}

//Trim function using find_first_not_of and find_last_not_of methods
inline std::string trim(const std::string &s){
	int st = s.find_first_not_of(" \t");
	int ed = s.find_last_not_of(" \t");

	if(st == -1){
		cout << "No Space found in the string " << endl ;
		return "";
	}
	return std::string(s, st, ed - st + 1);
}
void f8(){
	//std::string s = " 			This is the string			 ";
	std::string s = "	 This is the string	 	";
	std::string res =  trim(s);
	cout << "Original String " << s << endl;
	cout << "Original len " << s.length() << endl ;
	cout << "Trimmed String-" << res << "-end" << endl;
	cout << "Original len " << res.length() << endl ;
}
int main(){

	f8();
	return 0;
}
