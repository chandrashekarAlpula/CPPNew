
//: C04:StreambufIterator.cpp
// istreambuf_iterator & ostreambuf_iterator
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;
int main() {
ifstream in("StreambufIterator.cpp");
//assure(in, "StreambufIterator.cpp");
// Exact representation of stream:
istreambuf_iterator<char> isb(in), end;
ostreambuf_iterator<char> osb(cout);
while(isb != end)
*osb++ = *isb++; // Copy 'in' to cout
cout << endl;
cout << endl << endl << endl << "Steams " << endl << endl ;
ifstream in2("StreambufIterator.cpp");
// Strips white space:
istream_iterator<string> is(in2), end2;
ostream_iterator<string> os(cout);
while(is != end2)
*os++ = *is++;
cout << endl;
} ///:~
