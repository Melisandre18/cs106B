/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Writer problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "string.h"
#include "map.h"
#include <fstream>
#include<string>
#include <stdlib.h>
#include <cstdlib>
#include "random.h"
#include <cctype>

using namespace std;


string finaltxt(Map<string, Vector<char> > & map, string& s) {
	string str = s;
	string txt=s;
	char ch;
		for(int i=0; i<2000; i++) {
			if(map.containsKey(str)) {
				int rand=randomInteger(0,map.get(str).size()-1);
				ch = map.get(str)[rand];
				txt+=ch;
				str = str.substr(1) + ch ;
			}
		}
	return txt;
};

string comWord(Map<string, Vector<char> > txts){
    string com = "";
	int len = 0;
	foreach(string s in txts) {
		if(len<txts.get(s).size()) {
			com = s;
			len = txts.get(s).size();

		}
	}
	return com;
};

int main() {

   string filename=getLine("please enter the file name: ");
	ifstream file(filename.c_str());
	while(file.fail()){
		file.clear();
		cout<< "please enter the correct name: "<<endl;
		filename=getLine();
		file.open(filename.c_str());
	}
	int markov=getInteger("please enter markov order [1-10] : ");
	while(markov>10 ||markov<1){
		markov=getInteger("please enter correct markov order [1-10] : ");
	}
	char c;
    Map<string, Vector<char> > txts;
	string s="";
	while(s.size()!=markov){
		file.get(c);
		s+=c;
	}
	while (file.get(c)){ 
		if (isspace(s.at(0))&&(isspace(s.at(1)))){
			while(!isalpha(c)) file.get(c);
		}
		if(txts.containsKey(s)){
			Vector <char> &vec = txts.get(s);
			vec.add(c);
			txts.put(s,vec);
		}else{
			Vector<char>vec;
			vec.add(c);
			txts.put(s,vec);
		}
		s=s.substr(1)+c;
		
	}
	string common=comWord(txts);
	cout<<finaltxt(txts,common)<<endl;
	file.close();
      return 0;
   }