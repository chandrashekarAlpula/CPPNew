/*
 * DesignPrinciples.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
using namespace std;
enum class Color{red, blue, green};
enum class Size{small, medium, large};

struct Product{
	string name;
	Color color;
	Size size;
public:
	Product(string name, Color color, Size size) : name(name), color(color), size(size){}
	~Product(){	}
};

template<typename T>
struct AndSpecification;

template<typename T>
struct OrSpecification;

template<typename T>
struct ISpecification{
	virtual bool IsSatisfied(T * item) = 0;
	virtual ~ISpecification(){}
	AndSpecification<T> operator&&(ISpecification<T> &spec){
		return AndSpecification<T>{*this,spec};
	}
	OrSpecification<T> operator||(ISpecification<T> &obj){
		return OrSpecification<T>(*this,obj);
	}
};

template<typename T>
struct IFilter{
	virtual vector<T *> filter(vector<T *> items, ISpecification<T> &spec) = 0;
};

struct  BetterFilter : public IFilter<Product>{
	vector<Product *> filter(vector<Product *> items, ISpecification<Product> &spec){
		vector<Product *> res;
		for(auto &item : items){
			if(spec.IsSatisfied(item)){
				res.push_back(item);
			}
		}
		return res;
	}
};

struct ColorSpecification : public ISpecification<Product>{
	Color color;
	ColorSpecification(Color color) : color(color){}
	bool IsSatisfied(Product* item) {
		//cout << endl << "IN color" << endl;
		//cout << "Item color " << item->name << endl;
		return item->color == color;
	}
};

struct SizeSpecification : public ISpecification<Product>{
	Size size1;
	SizeSpecification(Size size1) : size1(size1){}
	bool IsSatisfied(Product* item){
		//cout << endl << "IN Size" << endl;
		return size1 == item->size;
	}
};

template<typename T>
struct AndSpecification : public ISpecification<T>{
	ISpecification<T> &spec1;
	ISpecification<T> &spec2;
	AndSpecification(ISpecification<T> &first, ISpecification<T> &second) : spec1(first), spec2(second){}
	bool IsSatisfied(T* item) override{
		//cout << endl << "IN And" << endl;
		return (spec1.IsSatisfied(item) && spec2.IsSatisfied(item));
	}
};

template <typename T>
struct OrSpecification : ISpecification<T>{
	ISpecification<T> &first;
	ISpecification<T> &second;

	OrSpecification(ISpecification<T> &first, ISpecification<T> &second) : first(first), second(second){}
	bool IsSatisfied(T* item) override{
		return first.IsSatisfied(item) || second.IsSatisfied(item);
	}
};

int main(){

	Product tree{"tree", Color::green, Size::large};
	Product apple{"apple",Color::green,Size::medium};
	Product cherry{"cherry",Color::red, Size::small};
	Product tamato{"tamato",Color::red, Size::medium};
	Product plant{"plant", Color::green, Size::medium};
	Product seed{"seed",Color::green, Size::small};
	Product blueberry{"blueberry", Color::blue, Size::small};

	vector<Product *> items{&tree,&apple,&cherry,&tamato,&plant,&seed,&blueberry};
	ColorSpecification green(Color::green);
	ColorSpecification red(Color::red);
	SizeSpecification medium(Size::medium);
	SizeSpecification large(Size::large);
	SizeSpecification small(Size::small);

	//vector<Product *> res;
	BetterFilter fl;
	vector<Product *> res = fl.filter(items,green);
	for(auto &item : res)
		cout <<  item->name  << " ";
	cout << endl;

	res = fl.filter(items, medium);
	for(auto &item : res)
		cout <<  item->name  << " ";
	cout << endl;

	AndSpecification<Product> spec(red, small);
	res = fl.filter(items, spec);
	for(auto &item : res)
		cout <<  item->name  << " ";
	cout << endl;

	AndSpecification<Product> spec2 = red && medium;
	res = fl.filter(items, spec2);
	for(auto &item : res)
		cout <<  item->name  << " ";
	cout << endl;

		OrSpecification<Product> orObj = green || large;
		for(auto &item : fl.filter(items, orObj))
			cout <<  item->name  << " ";
		cout << endl;
	return 0;
}

