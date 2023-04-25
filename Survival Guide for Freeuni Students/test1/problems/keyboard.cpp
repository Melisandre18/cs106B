#include "keyboard.h"
#include "strlib.h"


char arr[] = {'?', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

void getAllEncryption(string digits, Set<string> &words, Lexicon &lex) {
	map<int,char>dig;
	int n=1;
	for(char ch='a'; ch<='z'; ch++){
      dig.put(n,ch);
	  n++;
	}
	string wd="";
	foreach(char c in digits){
       int dg=(int) c;
	   wd+=dig.get(dg);
      
	}
	if(lex.contains(wd)) words.add(wd);
	wd="";
	for(int i=0; i<digits.lenght()-2; i++){
		
		if(map.containsKey((int)(digits.substr(i, i+2))))
		{   i+=2; 
			wd+=map.get(int(s));
		}else{
        ws+=map.get(digits[i]);
		}

	if(lex.contains(wd)&& !words.contains(wd)) words.add(wd);
	wd="";
	foreach (string w in words) cout<<w<<endl;
};
	
}
