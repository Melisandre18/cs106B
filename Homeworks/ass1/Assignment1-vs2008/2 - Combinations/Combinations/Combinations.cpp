/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h";
using namespace std;

int countN(int n){
	if(n==0){ 
		return 1;
	}else {
		return n*countN(n-1);
	}
};

int countK(int k){
	if(k==0){ 
		return 1;
	}else {
		return k*countK(k-1);
	}
};
int countNK(int num){
	if(num==0){ 
		return 1;
	}else {
		return num*countNK(num-1);
	}
};

int main() {
	int fir=getInteger("Enter first number: ");
	int sec=getInteger("Enter secod number: ");
	int num1=countK(sec-1)*countNK(fir-sec);
	int num2=countK(sec)*countNK(fir-1-sec);
	int upfirst= countN(fir-1)/num1;
	int upsecond=countN(fir-1)/num2;
	cout<<"Triangle number is: " <<upfirst+upsecond<<endl;
    return 0;
}
