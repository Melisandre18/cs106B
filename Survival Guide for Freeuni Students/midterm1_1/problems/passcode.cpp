#include "passcode.h"
#include "Set.h"
#include "Vector.h"
#include <string>
using namespace std;
/*** How to use passed function ***
	if (isCorrectCode("asd")) {
		return "asd";
	}
*/

void  getCode(string digits, int maxLength,
			   bool (*isCorrectCode)(string), string res,string& pass){
				   if(isCorrectCode(res)) {
					   pass=res;
					   return;
				   }
				   if(res.size()>maxLength) return;
				   for(int i=0; i<digits.size(); i++){
					 getCode( digits, maxLength,
			   *isCorrectCode,res+digits[i],pass);
				   }
}

string crackCode(string digits, int maxLength,
                bool (*isCorrectCode)(string))
{
	string res,pass;

         getCode(digits, maxLength,
                isCorrectCode,res,pass);
	return pass;
	
}

