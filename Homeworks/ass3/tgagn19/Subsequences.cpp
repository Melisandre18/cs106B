/*
 * File: Subsequences.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Subsequences problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence){
	string sub=subsequence;
	if(sub.length()==0) return true;
	if(sub.length()!=1){
	if(text.find(sub[0])<text.find(sub[1])){
		 return isSubsequence(text,sub.substr(1));
	}
	}else{
		if(text.find(sub[0])<text.length()) return true;
	}
	return false;
};

int main() {
	string one=getLine();
	string two=getLine();
	cout<<isSubsequence(one,two)<<endl;
    return 0;
}
