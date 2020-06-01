/*
 * STL_Inhertitance.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>

class FileEditor : public std::vector<std::string>{
public:
	FileEditor(char *fileName){
		std::ifstream in(fileName);
		std::string line ;
		while(getline(in, line)){
			push_back(line);
		}
	}
	void Print(){
		for(iterator itr = begin(); itr != end(); itr++)
			std::cout << *itr << " " ;
		std::cout << std::endl;

	}
	void Write(std::ostream &out = std::cout){
		std::copy(begin(), end(), std::ostream_iterator<std::string>(out, "\n"));
	}
};
int main(int argc, char *argv[]){
	if(argc < 3){
		std::cout << std::endl << "Wrong arguments " << std::endl ;
		return 0;
	}
	FileEditor file1(argv[1]);
	std::cout << std::endl << "Printing Vector element " << std::endl;
	file1.Print();
	std::cout << std::endl << "Printing File contents " << std::endl;
	std::ofstream of(argv[2]);
	file1.Write(of);
	return 0;
}



