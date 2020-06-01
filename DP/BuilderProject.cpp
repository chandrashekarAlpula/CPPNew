#include<iostream>
#include<string>
using namespace std;

class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person{
public:
	//address
	std::string street_addr, post_Code, city;
	//Works
	std::string company_name, position;
	int annualSal;
public:
	friend std::ostream& operator<<(std::ostream &out, const Person &p){
		out << endl << "Person lives in " << p.street_addr << " with Postal code " << p.post_Code << " and in city " << p.city << " ";
		out << "works in " << p.company_name << " as a " << p.position << " with annual earning " << p.annualSal << endl;
		return out;
	}
	static PersonBuilder create(){
		return PersonBuilder();
	}
	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;


};

class PersonBuilderIntf{
protected :
	Person &p;
public:
	PersonBuilderIntf(Person &p) : p(p){}

	operator Person() const {
		std::move(p);
	}
	PersonAddressBuilder lives(){
		return PersonAddressBuilder(p);
	}
	PersonJobBuilder works(){
		return PersonJobBuilder(p);
	}

};

class PersonBuilder : public PersonBuilderIntf{

public :
	Person person;
public:
	PersonBuilder() : PersonBuilderIntf(person){}
};

class PersonAddressBuilder : public PersonBuilderIntf{
	typedef PersonAddressBuilder self;
public :
	PersonAddressBuilder(Person &p) : PersonBuilderIntf(p){}
	self &at(const string &street){
		p.street_addr = street;
		return *this;
	}
	self &with(const std::string &pin){
		p.post_Code = pin;
		return *this;
	}
	self &in(const std::string city){
		p.city = city;
		return *this;
	}
};


class PersonJobBuilder : public PersonBuilderIntf{
	typedef PersonJobBuilder self;
public:
	PersonJobBuilder(Person &p) : PersonBuilderIntf(p){}
	self &at(const std::string comp){
		p.company_name = comp;
		return *this;
	}
	self &as(const std::string &desig){
		p.position = desig;
		return *this;
	}
	self &with(const unsigned int &sal){
		p.annualSal = sal;
		return *this;
	}
};

int main(){

	Person p = Person::create().
			lives().
			in("Bangalore").at("VS Challet, LB Shastri Nagar").with("560018").works().
			at("GlobalLogic Ind Ltd").as("Sr Consultant").with(200000);
	cout << p;


	return 0;
}
