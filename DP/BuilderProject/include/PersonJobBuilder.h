#pragma once
#include <string>

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

