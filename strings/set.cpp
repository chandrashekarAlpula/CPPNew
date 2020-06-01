#include<iostream>
#include<set>

int main(){

	std::set<unsigned int> test_set;
	test_set.insert(10);
	test_set.insert(22);
	test_set.insert(4);
	test_set.insert(12);
	test_set.insert(33);

//	std::set<unsigned int>::iterator i=test_set.begin();
	for(auto &elem : test_set){
		printf("test set first %d\n",elem);
	}
	return 0;
}
