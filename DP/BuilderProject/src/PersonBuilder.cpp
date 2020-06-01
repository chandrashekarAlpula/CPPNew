#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderIntf:: PersonBuilderIntf(Person &p) : p(p){
}

PersonAddressBuilder PersonBuilderIntf::Name(){
	return PersonAddressBuilder(p);
}
PersonAddressBuilder PersonBuilderIntf::lives(){
	return PersonAddressBuilder(p);
}
PersonJobBuilder PersonBuilderIntf::works(){
	return PersonJobBuilder(p);
}

PersonBuilder::PersonBuilder() : PersonBuilderIntf(person){}
