#include <bits/stdc++.h> 
#include<string>
using namespace std; 
  
int main() 
{ 
    int i = 942; 
    std::string str  = "0XFF";
    stringstream ss; 
    ss << hex << str; 
    ss >> i;
    string res = ss.str(); 
    cout << "0x" << res << endl; // this will print 0x3ae 
    cout << "I value is "<< i << endl;
    return 0; 
} 
