#include<iostream>
#include<memory>
/**
	PIMPL - Pointer to implementation
**/
using namespace std;

class User{
private:
	class pimpl;
	unique_ptr<pimpl> mPimpl;

public:
	User(const std::string &name, const double sal);
	~User(){
		cout << "User Dest" << endl;
	}
	std::string GetName();
	double GetSalary();
};


int main(){

	User usr("chandra", 15000.345);
	cout << endl << "Name " << usr.GetName() << " and Salary " << usr.GetSalary() << endl;
	return 0;
}
