/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "string.h"
using namespace std;

/* Function prototypes */


string intToString(int n){
	if(n>0 || n==0){
	if(n==0) {
		return string()+ char(0+'0');
	}else{
		if(n<10){
		return string()+ char(n+'0');
		}else {
		return intToString(n/10)+ string()+char((n%10)+'0');
	}
	}
	}else{
		n=n*(-1);
		if(n<10){
		return "-"+string()+ char(n+'0');
		}else {
		return "-"+intToString(n/10)+ string()+char((n%10)+'0');
	}
	}
	};


int stringToInt(string str){
	if(str.size() ==0) {
		return 0;
	}
	if(str[0]=='-'){
		if(str.size()==2){
			return (str[1] -'0')*(-1);
		}else{
			str=str.substr(1,str.size());
		    return (stringToInt(str))*(-1);
		}
	}else{
		if(str.size()==1){
			return str[0]-'0';
		}else{
			char last =str[str.size()-1];
			str=str.substr(0,str.size()-1);
			return stringToInt(str)*10 + (last-'0');
		}
	}
};

/* Main program */

int main() {
	int n=getInteger("Enter number: ");
	string str=getLine("Enter word: ");
	cout<<intToString(n)<<endl<<stringToInt(str)<<endl;
    return 0;
}
