#include "expression.h"
#include "strlib.h"
#include "vector.h"
#include "set.h"


int getExpressionNum(int num, Set<int> nums) {
	Vector<int> nums1;
	foreach( int n in nums){
		nums1.add(n);
	}
	Vector<Set<int>>exps;
	for(int i=0; i<nums1.size()-1; i++){
		for(int j=i+1; j<nums1.size(); j++){
			if((nums1.get(i)+nums1.get(j))==num || (nums1.get(i)-nums1.get(j))==num|| (nums1.get(j)-nums1.get(i))==num){
				Set<int>fornums;
				fornums.add(nums1.get(i));
				fornums.add(nums1.get(j));
				if (find(exps.begin(), exps.end(), fornums) != exps.end()) exps.add(fornums);

			}
		}
	}
	return exps.size();
};

