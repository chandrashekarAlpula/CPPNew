#include<iostream>
#include<string>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

using namespace std;
int main(){

	Person p = Person::create().Name().as("Chandra").lives().in("Bangalore").at("VS Challet, LB Shastri Nagar").
			with("560018").works().at("GlobalLogic Ind Ltd").as("Sr Consultant").with(200000);
	cout << p;


	return 0;
}
