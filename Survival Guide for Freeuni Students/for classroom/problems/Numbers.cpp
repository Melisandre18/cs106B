#include "Numbers.h"
#include "vector.h"
#include <iostream>
#include <string>
#include "simpio.h"


void getNum(int n, int k, int num, Vector<int> &vec){
	if(n==0) {
			vec.add(num);
			return;
	//	}
	}
	while(true){
		if(num%10-k>=0) getNum(n-1,k,num*10+(num%10-k),vec);
	    if(num%10+k<=9&&k!=0) getNum(n-1,k,num*10+(num%10+k),vec);
		num++;
		if(num>=10) return;
	}

		
		
}
Vector<int> numsSameConsecDiff(int n, int k){
	Vector<int>numd;
	getNum(n-1,k,1,numd);
	cout<<numd;
	return numd;
};


//mishpsiiiiii
/*
void getNum(int n, int k, int num, Vector<int>& vec){
	if(n == 0){
		 vec.add(num);
		return;
	}

	if(num == 0){ // starting of a number
		for(int i = 1; i <= 9; i++){ // a number could not be started with 0
			getNum(n - 1, k, num + i,  vec);
		}
	}else{ // find next digit based on the prev one.Like lastdigit+/-k
		int lastDigit = num % 10;

		int nextPossibleNumber2 = lastDigit + k;
		int nextPossibleNumber1 = lastDigit - k;

		if(nextPossibleNumber1 >= 0 && nextPossibleNumber1 < 10){
			getNum(n - 1, k, num*10 + nextPossibleNumber1,  vec);
		}
		if(nextPossibleNumber2 >= 0 && nextPossibleNumber2 < 10 && nextPossibleNumber2!= nextPossibleNumber1){
			getNum(n - 1, k, num*10 + nextPossibleNumber2,  vec);
		}
	}
}



Vector<int> numsSameConsecDiff(int n, int k) {
	Vector<int> nums;
	getNum(n, k, 0, nums);
	return nums;
}



*/




/*


*/
