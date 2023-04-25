/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include <string>
#include "simpio.h"
#include <vector>
#include <queue>
#include <set>
#include "queue.h"
#include <algorithm>
#include "vector.h"
using namespace std;

void getVec(Lexicon &lexicon,string str, Queue<Vector<string>>&q,Set<string>&st, Vector<string>vec){
	    Lexicon ws;
		Vector<string>v;
		for(int i=0; i<str.length(); i++){
			for(char ch='a'; ch<='z'; ch++){
				string s = str;
				s[i]=ch;
				if(lexicon.contains(s)){
					if(!st.contains(s)){
						st.add(s);
						v=vec;
						v.add(s);
						q.enqueue(v);

					}
				}
			}
		}
};

Vector<string> finalVec(Lexicon& lexicon, string start, string& end){
	Queue<Vector<string>>q;
	Vector<string>v;
	v.add(start);
	q.enqueue(v);
	Set<string> st;
	while(!q.isEmpty()){
    Vector<string>mainVec=q.dequeue();
	string last=mainVec.get(mainVec.size()-1);
	if(last==end){
    return mainVec;
	}
	getVec(lexicon,last,q,st,mainVec);
	}
	return v;
};
int main() {
	while(true){
	string start=getLine("Enter the starting word (or nothing to quit) : ");
	if(start.size()==0) {
		cout<<"You quit."<<flush;
		return 0;
		break;
	}
	string end=getLine("Enter the ending word: ");
	Lexicon lex("EnglishWords.dat");
	Vector <string> vec;
	
	if(start.size()!=end.size()) {
		cout<<"No such word ladder exists."<<endl;
	}
	if(!finalVec(lex,start,end).isEmpty()){
		vec=finalVec(lex,start,end);
	}else{
		cout<<"No word ladder exists."<<endl;
		break;
	}
	if(vec.size()!=1){
		foreach(string word in vec){
			cout<<word;
			if (word!=vec.get(vec.size()-1)) cout<< " -> ";
			else cout<<endl;
			cout.flush();
		}	
		}
	}
    return 0;
}
