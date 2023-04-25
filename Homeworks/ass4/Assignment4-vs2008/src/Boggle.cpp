/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
#include "random.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const string STANDARD_CUBES[16]  = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
    "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
    "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

/* Function prototypes */

void welcome();
void giveInstructions();
void cubesToVector();

Vector<string> shuffleVec(int num,const  string cubes[]){
Vector<string>vec;
for(int i=0; i<num; i++){
	vec.add(cubes[i]);
}
	for(int i=0; i<vec.size(); i++){
	int x=randomInteger(i, vec.size()-1);
	string rem=vec[x];
	vec[x]=vec[i];
	vec[i]=rem;
}
	return vec;
};
Grid<char> boardGrid(int num, Vector<string>& vec) {
	Vector<string>vecc=vec;
      Grid<char> matrix(num,num);
      for (int i = 0; i < num; i++) {
		  for(int j=0; j<num; j++){
			  int x=randomInteger(i, vecc[j].size()-1);
			  matrix[i][j]=vecc.get(j)[x];
			  if (i!=num-1) vecc.remove(j);
			  labelCube( i, j, matrix[i][j]);
		  }
      }
      return matrix;
   };
bool isWord(string s, Lexicon &lex){
	if(lex.contains(s)&&s.length()>=4){
		return true;
	}
	return false;
};
bool findGridWord(string s, Grid<char> & gr, Grid<bool>  & check, int r, int c){
	if(s.length()==0) return true;
	for(int i=r-1; i<r+2; i++){
		for(int j=c-1; j<c+2; j++){
			if(i>=0 && j>=0 && i<gr.numRows() && j<gr.numCols()){
				if(check[i][j]==false){
					if(s[0]==gr[i][j]) {
						check[i][j]=true;
						s=s.substr(1);
						if(findGridWord(s, gr, check, i, j)) return true;
					}
				}
			}
		}
	}
	return false;
};
void computerWords(Grid<char> & gr, Grid<bool> check, int i, int j, string s,Lexicon &lex, Set<string>ps, int num){
	if(!lex.containsPrefix(s)) return;
	if(s.length()>=4 && isWord(s,lex) && !ps.contains(s)) {
		recordWordForPlayer(s,COMPUTER);
	}
	for(int r=i-1; r<=i+1; r++){
		for(int c=j-1; c<=j+1; c++){
			if(r>=0 && r<num &&c>=0 && c<num){
				if(check[r][c]==false){
					check[r][c]=true;
					s=s+gr[r][c];
					computerWords(gr,check,r,c,s,lex,ps,num);
					check[r][c]=false;
					s= s.substr(0,s.length()-1);
				}
			}
		}
	}
};
bool person(string s, Grid<char> & gr, Lexicon & lex){
	if(!isWord(s,lex)) return false; 
		for(int i=0; i<gr.numRows(); i++){
			for(int j=0; j<gr.numCols(); j++){
				Grid<bool> check(gr.numRows(), gr.numCols()); 
				if(s[0]==gr[i][j]){
					 check[i][j]=true;
					s=s.substr(1);
					if(findGridWord(s,gr,check, i, j)) {
						for(int k=0; k<gr.numRows(); k++){
							for(int t=0; t<gr.numCols(); t++){
								if(check[k][t])
								highlightCube(k, t, true);
							}
						}
						pause(1000);
						for(int k=0; k<gr.numRows(); k++){
							for(int t=0; t<gr.numCols(); t++){
								if(check[k][t])
								highlightCube(k, t, false);
							}
						}
						return true;
					}
				}
			}
		}
	return false;
};

/* Main program */

int main() {
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    initGBoggle(gw);
    welcome();
    giveInstructions();
	Lexicon lex("EnglishWords.dat");
	int num=getInteger("Enter the number of rows and columns for the board: " );
	drawBoard(num,num);
	Vector<string>cubeVec;
	string s=getLine( "Do you want to write combination? Type Yes or No: " );
	while(true){
	if(s=="NO"||s=="No"||s=="no"){
	if(num==4){
		cubeVec=shuffleVec(num*num, STANDARD_CUBES);
	}else {
		cubeVec=shuffleVec(num*num,  BIG_BOGGLE_CUBES);
	}
	break;
	}else if (s=="YES"||s=="Yes"||s=="yes"){
		int count=0; 
		while(count!=num){
			string chars=getLine("Enter string : ");
			while(true){
				if(chars.size()!=num) chars=getLine("Enter valid string : ");
				else {
					cubeVec.add(chars);
					count++;
					break;
				}
			}
			
		}
		break;
	}else{
		s=getLine("Enter valid word: ");
	}
}
	Grid<char> board(num,num);
	board=boardGrid(num,cubeVec);
	Set<string>playerSet;
	while(true){
		string w=getLine("Enter the word: ");
		if(w.size()==0) break;
			if(w.size()<4 || !lex.contains(w)){
			w=getLine("Word size should be min 4  and it should be valid , enter valid word: ");
		}
		int wr=0;
		int wc=0;
		for(int i=0; i<num; i++){
			for(int j=0; j<num; i++){
				if(w[0]==board[i][j]) {
					wr=i;
					wc=j;
				}
			}
		}
		string empty="";
		if(isWord(w,lex)){
	    for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			Grid<bool>check(num,num);
			empty = board[i][j];
			check[i][j] = true;
			findGridWord(board,check, i,j,empty,lex, s,num,playerSet);
		}
		}
		}
	}
	string empty="";
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			Grid<bool>check(num,num);
			empty = board[i][j];
			check[i][j] = true;
			computerWords(board,check, i,j,empty,lex, playerSet,num);
		}
	}
	
	return 0;
}




/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
}

// [TODO: Fill in the rest of the code]
