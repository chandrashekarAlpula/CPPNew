#include<iostream>
#include<memory>
using namespace std;

int main(){

	// allocator for integer values
	    std::allocator<int> myAllocator;

	    // allocate space for five ints
	    int* arr = myAllocator.allocate(5);

	    // construct arr[0] and arr[3]
	    myAllocator.construct(arr, 100);
	    arr[3] = 10;

	    std::cout << arr[3] << std::endl;
	    std::cout << arr[2] << std::endl;

	    // deallocate space for five ints
	    myAllocator.deallocate(arr, 5);

	    return 0;
}
