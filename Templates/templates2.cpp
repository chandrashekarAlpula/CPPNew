#include<iostream>
//using namespace std;


 const int & max(const int &a, const int &b){
	std::cout << "\n specialized max\n";
	return a > b ? a : b;
}


template<typename T>
const T & max(const T &a, const T &b){
	std::cout << "\n Non specialized max1\n";
	return a > b? a:b;
}

template<typename T>
T* const & max(T* const &a, T* const &b){
	std::cout << "\n Non specialized pointer max3\n";
	return *a > *b ? a : b;
}

template<typename T>
T const & max(T const &a, T const &b, T const &c){
	std::cout << "\n Non specialized max2\n";
	return max(max(a,b),c);
}

int gobal_var = 42;
void changeReferenceValue(const int * &pp)
{
   //pp = &gobal_var;
 //  *pp = 66;
}

void fun(){
	using namespace std;
	int var = 23;
	int* ptr_to_var = &var;

	cout << "Passing a Reference to a pointer to function" << endl;

	cout << "Before :" << *ptr_to_var << endl; // display 23

	//changeReferenceValue(ptr_to_var);

	cout << "After :" << *ptr_to_var << endl; // display 42
}
int main(){

	int a = 2, b = 7, c = 8;
	char d = 'a';
	double x = 2.5, y = 7.6;
	std::cout << std::endl << " max(2,7) " << max(a,b) << std::endl;
	std::cout << std::endl << " max<int>(2,7) " << max<const int>(2,6) << std::endl;
	std::cout << std::endl << " max<>(2,7) " << max<int>(a,b) << std::endl;
	std::cout << std::endl << " max(&a, &b) " << *(max(&a, &b)) << std::endl;

/*	std::cout << std::endl << " max<int>('a',7) " << max<int>(d,b) << std::endl;
	std::cout << std::endl << " max(2.5,7.0) " << max(x,y) << std::endl;
	std::cout << std::endl << " max<double>(2.5,7.0) " << max<double>(x,y) << std::endl;
	std::cout << std::endl << " max(2,7,8) " << max(a, c,b)<< std::endl;
	*/

	int u = 10;
	int v = 40;
	const int *pp = &u;
	const int * &p = pp;
	*p = 20;

	//p = 20;
	//p = &v;

	//fun();

	return 0;
}
