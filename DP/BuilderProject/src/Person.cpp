#include"Person.h"
#include "PersonBuilder.h"

std::ostream& operator<<(std::ostream &out, const Person &p){
	out << endl << "Person " << p.name << " lives in " << p.street_addr << " with Postal code " << p.post_Code << " and in city " << p.city << " ";
	out << "works in " << p.company_name << " as a " << p.position << " with annual earning " << p.annualSal << endl;
	return out;
}

PersonBuilder Person::create(){
	return PersonBuilder();
}
