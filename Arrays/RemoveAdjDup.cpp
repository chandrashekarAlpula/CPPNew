/*
 * RemoveAdjDup.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<string.h>

using namespace std;

void RemoveAdjDup(char *s){
	int len = strlen(s);
	int i = 0, j = -1;
	while(i < len){
		if(j == -1 || s[i] != s[j]){
			s[++j] = s[i++];
		}else{
			i++;
		}
	}
	s[++j] = '\0';
}
int main(){

	char s[] = "aaabbbbccdeee";
	cout << endl << "Str Before " << s;
	RemoveAdjDup(s);
	cout << endl << "Str After " << s << endl ;
	RemoveAdjDup(s);
	return 0;
}



