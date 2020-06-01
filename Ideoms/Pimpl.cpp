#include<pimpl.h>

struct User::pimpl {

public:
		pimpl(const std::string &name, const double sal) : name(name), sal(sal){}
		~pimpl(){
			cout << "Pimpl Dest" << endl;
		}

	std::string name;
	double sal;
};

User::User(const std::string &name, const double sal) : mPimpl(new pimpl(name,sal)) {
	cout << "Welcome " << endl ;
}

std::string User::GetName(){
	return mPimpl->name;
}

double User::GetSalary(){
	return mPimpl->sal;
}
