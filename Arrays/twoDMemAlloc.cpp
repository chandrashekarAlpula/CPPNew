#include<iostream>
#include<stdio.h>

using namespace std;


int r = 4;
int c =  3;

int main(){
	//Creating 10*2 array

	//int **A = (int **)malloc(sizeof(int *) * r);
	int **A = new int*[r];

	for(int i = 0; i < r; i++){

		//A[i] = (int *)malloc(sizeof(int) * c);
		A[i] = new int[c];
	}
	int cnt = 1;
	for(int i = 0;  i< r; i++)
		for(int j = 0; j  < c; j++)
			A[i][j] = cnt++;
	cout << endl;
	 for(int i = 0;  i< r; i++){
                for(int j = 0; j  < c; j++){
			cout << A[i][j] <<  " ";	
		}
		cout << endl;
	}
	return 0;

}
