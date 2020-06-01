#include<iostream>
#include<string>

using namespace std;

struct Address{
	string street, city;
	int suit;

	Address(const string &street, const string &city, const int &suit) : street{street}, city{city}, suit{suit}{}

	Address(const Address &address) : street{address.street}, city{address.city}, suit{address.suit}{}

	friend std::ostream &operator <<(std::ostream &out, const Address &address){
		out << "Street : " << address.street << " City : " << address.city << " Suit: " << address.suit << "\n" ;
		return out;
	}
};

struct Contact{
	string name;
	Address *address;

	Contact(const string &name, Address *address) : name(name), address(address){}
	Contact(const Contact &other) : name{other.name}, address{new Address{*other.address}} {}

	friend std::ostream &operator<<(std::ostream &out, const Contact &contact){
		out << "Name: " << contact.name << " " << *contact.address;
		return out;
	}


};



int main(){

	Contact ch{"Chandra", new Address{"LB Shastri nagar", "Bangalore", 123}};
	Contact ran = ch;
	ran.name = "Ranjitha";
	ran.address->suit = 103;
	cout << ch;
	cout << ran;
	return 0;
}
