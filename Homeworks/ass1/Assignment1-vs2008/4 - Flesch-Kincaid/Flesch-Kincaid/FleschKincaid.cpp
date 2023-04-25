/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include <string>
using namespace std;
double c0=-15.59;
double c1=0.39;
double c2=11.8;

bool isOrNot(char c){
char ch[]={'a', 'e', 'i', 'o', 'u', 'y'};
for(int j=0; j<sizeof(ch); j++){
	if(ch[j]==c) return true;
}
return false;
}

void read(){
	string filename=getLine("please enter the file name: ");
	ifstream file(filename.c_str());
	string txt;
	while(file.fail()){
		file.clear();
		cout<< "please enter the correct name: "<<endl;
		filename=getLine();
		file.open(filename.c_str());
	}
	int sentences=0;
	int words=0;
	int syl=0;
	TokenScanner scanner;
	scanner.ignoreWhitespace();
	ifstream input;
	while (getline(file,txt)) {
		scanner.setInput(txt);
		scanner.addWordCharacters("'");
		while(scanner.hasMoreTokens()){
			string token=scanner.nextToken();
			if(token=="." || token=="?" || token =="!") sentences++;
			if(isalpha(token[0])) {
				words++;
			int tks=0;
			for(int i=0; i<token.size()-1; i++){
				token[i]=tolower(token[i]);
				if(isOrNot(token[i])){
				 if(!isOrNot(token[i+1])){
				    syl++;
					tks++;
					}
				 if(i==token.size()-2&&token[i+1]=='e'){
                    syl++;
					tks++;
					}
				}
			}
			if(token[token.size()-1]!='e' && isOrNot(token[token.size()-1])) {
				syl++;
				tks++;
			}
			if(tks==0) syl++;
			tks=0;
		}
		}
		
	}
	double grade= c0+c1*((double)words/sentences)+c2*((double)syl/words);
	if(sentences>0 && words>0 &&syl>0){
		
		cout<<"Sentences: " <<sentences <<endl <<"Words: " <<words<<endl<<"Syllables: "<<syl<<endl<<"Grade: " <<grade<<endl;
	}else{
		words=1;
		sentences=1;
		syl=1;
		cout<<"sentences: " <<sentences <<endl <<"words: " <<words<<endl<<"syllables: "<<syl<<endl<<"Grade: " <<grade<<endl;
	}
	file.close();
};
int main() {
	read();
    return 0;
}
