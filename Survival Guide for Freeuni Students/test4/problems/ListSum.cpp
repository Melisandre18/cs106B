#include "ListSum.h"

digit* rev(digit* curr) {
	digit* newD = NULL;
	while (curr != NULL) {
		digit* newDigit = new digit;
		newDigit->d = curr->d;
		newDigit->next = newD;
		newD = newDigit;
		curr = curr->next;
	}
	return newD;
}
digit * sum(digit * first, digit* second) {
   digit* head= rev(first);
   digit* tmp=rev(second);
   digit * node = new digit;
        int add = 0;
        while (head != NULL || tmp != NULL) {
            int sum = add;
            if (head!= NULL) {
				sum += head->d;
               head=head->next;
            }
            if (tmp != NULL) {
				sum += tmp ->d;
               tmp =tmp ->next;
            }
            
			int count=0;
			if(sum>10){
				count=1;
				sum=sum%10;
			}
          if (count==0) node->next->d=sum;
		  else node->next->d=sum+1;
        }
		 node =rev(node);
      
        return node;
    }


