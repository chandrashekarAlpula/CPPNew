#pragma once

#include<iostream>
#include<string>
using namespace std;

class PersonBuilder;
//class PersonAddressBuilder;
//class PersonJobBuilder;

class Person{
private:
	//address
	std::string name, street_addr, post_Code, city;
	//Works
	std::string company_name, position;
	int annualSal;
public:
	friend std::ostream& operator<<(std::ostream &out, const Person &p);
	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;


};
