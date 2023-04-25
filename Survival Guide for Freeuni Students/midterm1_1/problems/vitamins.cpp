#include "vitamins.h"

#include "vector.h"
using namespace std;



//dasamtavrebelia

void getVec(Set<string> vitamins, Vector< Set<string> > fruits, Vector<int> answer, Set<string>resu){
	if(vitamins.size()==0) return;
	string vit= vitamins.first();
	for(int i=0; i<fruits.size(); i++){
		if(fruits[i].contains(vit)&&!(fruits[i].isSubsetOf(resu))) {
			if(resu.isSubsetOf(fruits[i]){
				final.add(i);
				resu.clear();
				resu+=fruits[i]

			}
			answer.add(i);
			resu+=fruits[i];
		}
	}
	vitamins.remove(vit);
	getVec(vitamins, fruits,answer,resu);
	cout<<answer;
}
Vector<int> fruitList(Set<string> vitamins, Vector< Set<string> > fruits) {
	Vector<int> answer;
	Set<string>resu;
    getVec(vitamins, fruits, answer, resu);
	return answer;
}