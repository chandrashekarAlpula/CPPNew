#include<iostream>
#include<vector>

using namespace std;


struct Neuron;
template<typename Self>
struct NeuralIntf{
	template<typename T>
	void connect_to(T &obj){
		for(Neuron &from : *(static_cast<Self *>(this))) {
			for(Neuron &to : obj) {
				from.out.emplace_back(&to);
				to.in.emplace_back(&from);
			}
		}
	}
};

struct Neuron : public NeuralIntf<Neuron> {
	int id;
	std::vector<Neuron *> in, out;
	Neuron(){
		static int _id = 1;
		id = _id++;
	}

	void connect_to(Neuron &obj){
		//out.emplace_back(&obj);
		//obj.in.emplace_back(this);
	}

	Neuron *begin(){
		return this;
	}
	Neuron *end(){
		return this + 1;
	}
	friend std::ostream &operator<<(std::ostream &os, const Neuron &obj){
		for(Neuron *n : obj.in)
			os << n->id << "\t-->\t" << "[" << obj.id << "]" << endl;

		for(Neuron *n : obj.out)
			os << "[" << obj.id << "]" << "\t-->\t" << n->id << endl ;
		return os;
	}
};


struct NeuralLayer : public vector<Neuron>, public NeuralIntf<NeuralLayer>{
	int id;
	NeuralLayer(int size){
		while(size --> 0)
			emplace_back(Neuron{});
	}

	friend std::ostream &operator<<(std::ostream &os, const NeuralLayer &obj){
		for (auto &n : obj) os << n ;
		return os;
	}

};
int main(){
	Neuron n1,n2,n3;
	n1.connect_to(n2);
	n3.connect_to(n1);
	cout << n1 << endl ;

	NeuralLayer l1{2}, l2{3};
	l1.connect_to(l2);
	l1.connect_to(n1);

	cout << "Layer l1" << endl << l1 << endl;
	cout << "Layer l2" << endl << l2 << endl;
	return 0;
}
