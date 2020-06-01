#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Widget{
public:
	int i, j[10];
	Widget(int x = 20): i(x){
		cout << "In Constructor" << endl;
	}
	~Widget(){
		cout << "In Distructor" << endl;
	}
	Widget(const Widget &&p){
		this->i = p.i;
	}
	Widget &operator=(Widget &&p){
		this->i = p.i;
		return *this;
	}
};

std::unique_ptr<Widget> MakeWidget(){
	std::unique_ptr<Widget> p(new Widget{});
	//p.reset(new Widget{});
	cout << endl << "In Make widget size of unique ptr " << sizeof(p) << endl;
	return p;
}
void fun(std::shared_ptr<Widget> sp){
	//cout << "I value is " << sp->i << endl ;
	std::cout << "fun: sp.use_count() == " << sp.use_count() << '\n';
}

void test1(){

	cout << "main begin\n";
		{
		std::shared_ptr<Widget> s2 = MakeWidget();
		cout << "Back to main\n";
		std::cout << "Main: s2.use_count() == " << s2.use_count() << '\n';
		fun(s2);
		std::cout << "Main: s2.use_count() == " << s2.use_count() << '\n';

		cout << "Size of widget " << sizeof(Widget) << " and size of sp " << sizeof(s2) << endl;

		std::shared_ptr<Widget> sp1(nullptr);
		std::unique_ptr<Widget> s1(new Widget());
		{
			//std::shared_ptr<Widget> s3 = std::move(s1);
			//cout << "I value is " << s3->i << endl ;
			sp1 = std::move(s1);
		}
		}
		std::vector<std::shared_ptr<Widget>> vsp;
		for(int i = 1; i <= 3; i++)
			vsp.push_back(std::shared_ptr<Widget>(new Widget(i)));
		cout << "After Creation" << endl ;
		cout << "main end\n";

}

class WidgetTest{
public:
	std::unique_ptr<Widget> ptr;
	WidgetTest() : ptr{nullptr}{
	}
	WidgetTest(std::unique_ptr<Widget> &ptr) : ptr{std::move(ptr)}{
		cout << "\n HERE 1 \n";
	}
	WidgetTest(std::unique_ptr<Widget> &&ptr) : ptr{std::move(ptr)}{
		cout << "\n HERE 2 \n";
	}
//	~WidgetTest(){}
	/*WidgetTest(WidgetTest &&p):ptr{p.ptr} {

	}
	WidgetTest &operator=(WidgetTest &&p){
		//ptr.reset(new WidgetTest{});
		return *this;
	}*/
	/*WidgetTest(const WidgetTest & p){
		ptr = std::move(p.ptr);
	}
	WidgetTest &operator=(const WidgetTest &p){
		ptr = std::move(p.ptr);
		return *this;
	}
	WidgetTest(WidgetTest &&p) ;
	WidgetTest &operator=(WidgetTest &&p) ;
	*/

private :

};

//WidgetTest::WidgetTest(WidgetTest &&p) = default;
//WidgetTest &WidgetTest::operator=(WidgetTest &&p) = default;

void test2(){
	{
		//std::unique_ptr<Widget> p(new Widget());
		//cout << "Get  " << p.get() << "\n";
		WidgetTest t(std::unique_ptr<Widget>(new Widget()));
		WidgetTest t1;
		t1 = std::move(t);
		cout << "Get  " << t.ptr.get() << "\n";
	}

}

int gcnt = 0;
struct A{
	int cnt;
	A() {
		std::cout << std::endl << "In CONST " << (++gcnt) ;
	}

	~A(){
	std::cout << std::endl << "In DIST "  << (--gcnt);
	}
};

struct B{
	std::shared_ptr<A> p1;
	B(std::unique_ptr<A> &uptr) : p1{std::move(uptr)}{}
	B() : p1{nullptr}{}
};

void f1(std::unique_ptr<A> &&p1, std::vector<B> &v1){

	//B b(p1);
	B b;
	v1.push_back(b);
}

void test3(){
	std::unique_ptr<A> p1;
	std::vector<B> v1;
	for(int i= 0; i < 5; i++){
		f1(std::unique_ptr<A>(new A()), v1);
		std::cout << std::endl << "In loop ";

		//A *b = p1.get();
		//p1.reset();
	}
	while(!v1.empty()){
		B b = v1.back();
		cout << endl << "HERE" ;
		v1.pop_back();
	}
	std::cout << std::endl << "End of fun ";
}
int main(){
	test3();
}
