#pragma once
#include <string>


class PersonAddressBuilder : public PersonBuilderIntf{
	typedef PersonAddressBuilder self;
public :
	PersonAddressBuilder(Person &p) : PersonBuilderIntf(p){}
	self &as(const std::string &name){
		p.name = name;
		return *this;
	}
	self &at(const std::string &street){
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
