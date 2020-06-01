#pragma once

#include "Person.h"
//#include "PersonAddressBuilder.h"
//#include "PersonJobBuilder.h"


class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderIntf{
protected :
	Person &p;
public:
	PersonBuilderIntf(Person &p);
	operator Person() const {
		//return std::move(p);
		return p;
	}
	PersonAddressBuilder Name();
	PersonAddressBuilder lives();
	PersonJobBuilder works();

};

class PersonBuilder : public PersonBuilderIntf{

public :
	Person person;
public:
	PersonBuilder() ;
};
