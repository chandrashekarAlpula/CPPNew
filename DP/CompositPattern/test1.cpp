#include<iostream>
#include<vector>

using namespace std;

class Neuron;
template<typename Self> class NeualIntf{
public:
	template<typename T> void connect_to(T &obj){
		for(Neuron &from : *static_cast<Self *>(this)){
			for(Neuron &to : obj){
				from.out.emplace_back(&to);
				to.in.emplace_back(&from);
			}
		}
	}
};

class Neuron : public NeualIntf<Neuron>{
public :
	unsigned int id;
	std::vector<Neuron *> in,out;
	Neuron(){
		static int _id = 1;
		id = _id++;
	}
	Neuron *begin(){
		return this;
	}
	Neuron *end(){
		return this+1;
	}
	/*void connect_to(Neuron &obj){
		out.emplace_back(&obj);
		obj.in.emplace_back(this);
	}*/
	friend std::ostream &operator<<(std::ostream &os, const Neuron &obj){

		for(auto n : obj.in) os << n->id << "\t-->\t" << "[" << obj.id << "]" << endl;
		for(auto n : obj.out) os << "[" << obj.id << "]" << "\t-->\t" << n->id << endl;
		return os;
	}
};

class NeuralLayer : public std::vector<Neuron>, public NeualIntf<NeuralLayer>{
public:
	NeuralLayer(int sz){
		while(sz --> 0)
			emplace_back(Neuron{});
	}

	friend std::ostream &operator <<(std::ostream &os, const NeuralLayer &obj){
		for(const Neuron &n : obj) os << n;
		return os;
	}
};

int main(){

	Neuron n1,n2,n3;
	n1.connect_to(n2);
	n2.connect_to(n3);


	cout << "N1  \n" << n1 << endl;
	cout << "N2  \n " << n2 << endl;

	NeuralLayer l1{2}, l2{3};
	l1.connect_to(n1);
	l2.connect_to(n2);
	l1.connect_to(l2);

	cout << "L1  \n" << l1 << endl;
	cout << "L2  \n " << l2 << endl;

	return 0;
}
