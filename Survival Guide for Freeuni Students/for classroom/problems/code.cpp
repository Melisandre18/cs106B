#include "Code.h"
#include "vector.h"
#include <string>



void getCode(int n, string s, Vector<string> &vec, string str){
	if(str.size()>n) return;

	if(str.size()==n) {
		vec.add(str);
		return;
	}

	for(int i=0; i<s.size(); i++){
		getCode(n,s, vec, str+s[i]);
	}
}
Vector<string> generateCodes(int n, string symbols) {
	Vector<string> codes;	
	getCode(n,symbols,codes,"");
	return codes;
}