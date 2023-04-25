/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
#include "simpio.h"
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.

 */
bool ifSubset(Set<string>st, Vector<Set<string>>vec){
	Set<string>ForVec;
	for(int i=0; i<vec.size() ; i++){
		ForVec+=vec.get(i);
	}
	if(st.isSubsetOf(ForVec)) return true;
	return false;
};
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
							   Vector< Set<string> >& result){
								  
if (numHospitals==0) return ifSubset(cities,result);
foreach(Set<string>loc in locations){
	result.add(loc);
	Vector<Set<string>>others;
	foreach(Set<string>locs in locations){
		if(locs!=loc){
			others+=locs;
		}
	}
	if(canOfferUniversalCoverage(cities, others, numHospitals-1, result)) return true;
		else  result.remove(result.size()-1);	
}
return false;
};


int main() {
    Set<string> cities;
	Vector<Set<string> > locations(5);
	Vector<Set<string> > result;
	cities.add("A");
	cities.add("B");
	cities.add("C");
	cities.add("D");
	cities.add("E");
	cities.add("F");
	cities.add("G");
	locations[0].add("A");
	locations[0].add("B");
	locations[1].add("A");
	locations[1].add("C");
	locations[1].add("D");
	locations[2].add("B");
	locations[2].add("F");
	locations[3].add("C");
	locations[3].add("D");
	locations[3].add("E");
	locations[4].add("G");
    int numHospitals=getInteger("Enter number of hospitals ");
	if(numHospitals<1||numHospitals>locations.size()) numHospitals=getInteger("Enter Valid Number: ");
	if(canOfferUniversalCoverage(cities,locations,numHospitals,result)){
		cout<<"You can cover cities" <<endl;
		cout<<result<<endl;
	} else{
		cout<<"No way to cover cities"<<endl;
	}
    return 0;
}
