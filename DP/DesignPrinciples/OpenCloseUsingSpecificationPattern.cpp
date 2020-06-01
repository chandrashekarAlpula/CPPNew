#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
struct Specification{
	virtual bool isStatisfied(T *item) = 0;
};

template <typename T>
struct IFilter{
	virtual std::vector<T *>  filter(std::vector<T *> &item, Specification<T> &spec) = 0;
};

enum class Color{red, green, yellow, blue};
enum class Size{small, medium ,  large};

std::vector<string> ColorToStr{"Red" , "Green", "Yellow"};
std::vector<string> SizeToStr{"Small", "Medium", "Large"};

struct Product{
	std::string title;
	Color color;
	Size size;
};

struct ColorSpecification : public Specification<Product>{
	Color color;
	explicit ColorSpecification(Color color) : color{color}{}

	bool isStatisfied(Product *item) override {
		return item->color == color;
	}
};

struct SizeSpecification : public Specification<Product>{
	Size size;
	SizeSpecification(Size size) : size{size}{}
	bool isStatisfied(Product *item) override{
		return item->size == size;
	}
};


struct Filter : public IFilter<Product>{
	 std::vector<Product *> filter(std::vector<Product *> &vec, Specification<Product> &spec){
		 std::vector<Product *> result;
		 for(auto &item : vec){
			 if(spec.isStatisfied(item))
				 result.push_back(item);
		 }
		 return result;
	 }
};


int main(){

	Product tree{"Tree", Color::green, Size::large};
	Product apple{"Apple", Color::red, Size::small};
	Product pen{"Pen", Color::blue, Size::small};
	Product book{"book", Color::yellow, Size::medium};
	Product plant{"Plant", Color::green, Size::small};

	Product car{"Car", Color::red, Size::large};
	Product bike{"Car", Color::blue, Size::medium};

	std::vector<Product *> vec{&tree, &apple, &pen, &book , &plant, &car, &bike};

	Filter fil;
	ColorSpecification green{Color::green};
	SizeSpecification small{Size::small};

	std::vector<Product *> res = fil.filter(vec,green);
	for(auto elem : res){
	//	cout << "title " << elem->title << " Color " << ((unsigned int)elem->color) << " Size " << ((unsigned int)elem->size )<< endl;
		cout << "title " << elem->title << ", Color " << ColorToStr[static_cast<unsigned int>(elem->color)] << ", Size " << SizeToStr[static_cast<unsigned int>(elem->size)] << endl;
	}
	return 0;
}
