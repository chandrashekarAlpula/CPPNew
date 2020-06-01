#include<iostream>
#include<vector>

using namespace std;

enum class Color{red ,green, yellow};
enum class Size{small, medium, large};

std::vector<string> ColorToStr{"Red" , "Green", "Yellow"};
std::vector<string> SizeToStr{"Small", "Medium", "Large"};


struct Product{
	std::string title;
	Color color;
	Size size;

	//Product(std::string &title, Color &color, Size &size) : title{title}, color{color}, size{size}{}

};

std::ostream &operator<<(std::ostream &os, const Product *p){
	//os << "title is " << p.title << ", color is " << p.color << ", size is " << p.size ;
	//os << "title is " << p->title << ", color is " << p->color << ", size is " << p->size ;
	os << "title " << p->title << ", Color " << ColorToStr[static_cast<unsigned int>(p->color)] << ", Size " << SizeToStr[static_cast<unsigned int>(p->size)];
	return os;
}


template<typename T>
struct Specification{
	virtual bool isSatisfied(T *item)= 0;
};

template<typename T>
struct Filter{
	virtual ::vector<T *> filter(std::vector<T *> items, Specification<T> &spec) = 0;
};

struct ColorSpecification : public Specification<Product>{
	Color color;
	ColorSpecification(Color color) : color{color}{}
	bool isSatisfied(Product *item){
		return item->color == color;
	}
};

struct SizeSpecification : public Specification<Product>{
	Size size;
	SizeSpecification(Size size) : size{size}{}
	bool isSatisfied(Product *item){
		return item->size == size;
	}
};

struct ColorAndSizeSpecification : Specification<Product>{
	ColorSpecification color;
	SizeSpecification size;
	ColorAndSizeSpecification(ColorSpecification color, SizeSpecification size) : color{color}, size{size}{}
	bool isSatisfied(Product *item){
		return (color.isSatisfied(item) && size.isSatisfied(item));
	}
};


struct CompositeSpecification : Specification<Product>{
	std::vector<Specification<Product> *> specVec;
	CompositeSpecification(std::vector<Specification<Product> *> list) : specVec{list}{}

	bool isSatisfied(Product *item){
		for(auto it : specVec){
			if(!it->isSatisfied(item))
				return false;
		}
		return true;
	}
};

struct ProductFilter: public Filter<Product>{
	std::vector<Product *> filter(std::vector<Product *> items, Specification<Product> &spec) override
	{
		std::vector<Product *> result;
		for(auto  *elem : items){
			if(spec.isSatisfied(elem)){
				result.push_back(elem);
			}
		}
		return result;
	}
};

int main(){

	Product apple{"Apple", Color::green, Size::small};
	Product cherry{"Cherry",Color::red, Size::small};
	Product muskmelon{"MuskMelon" , Color::yellow, Size::large};
	Product plant{"Plant", Color::green, Size::medium};
	Product gMango{"Green Mango", Color::green, Size::small};


	std::vector<Product *> products{&apple, &cherry, &muskmelon, &plant, &gMango};

	ProductFilter filter;
	ColorSpecification green{Color::green};
	SizeSpecification small{Size::small};

	//ColorAndSizeSpecification greenAndSmall{green, small};
	std::vector<Specification<Product> *> specVec;
	//{green, small};
	//std::initializer_list<Specification &> init{green, small};
	//specVec.push_back(&green);
	//specVec.push_back(&small);
	//CompositeSpecification greenAndSmall{specVec};
	CompositeSpecification greenAndSmall{{&green, &small}};

	std::vector<Product *> res = filter.filter(products, greenAndSmall);

	for(const auto item : res){
		cout << item << endl ;
	}
}
