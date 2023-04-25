#include "Browser.h"
#include <iostream>

Browser::Browser() {
	size=0;
	maxSize=10000;
	sizePage=1000;
	bro = new B*[maxSize];
}

void Browser::NewTab() {
	if(size>=maxSize){
		B** br= new B*[maxSize*2];
		for(int i=0; i<size; i ++){
			br[i]=bro[i];
		}
		bro=br;
		delete [] br;
	}
	B* newB= new B;
	newB->url=new string[sizePage];
	newB->pageNow=0;
	newB->pages=0;
	bro[size]=newB;
	size++;
}

void Browser::CloseTab(int tabIndex) {
	for(int i=tabIndex; i<size-1; i++){
			bro[i]=bro[i+1];
	}
	size--;

}

int Browser::Size() {
	return size;
}

void Browser::GoToPage(int tabIndex, string url) {

	/*
	if(bro[tabIndex]->pages>=sizePage){
		string *s= new string[sizePage*2];
		for(int i=0; i<bro[tabIndex]->pages; i++){
			s[i]=bro[tabIndex]->url[i];
		}
		bro[tabIndex]->url=s;
		delete [] s;
	}
*/


		if(bro[tabIndex]->pageNow!=0)
		{
			for(int i=bro[tabIndex]->pageNow; i<bro[tabIndex]->pages-1; i++){
					bro[tabIndex]->url[i]=bro[tabIndex]->url[i+1];
			}
			bro[tabIndex]->url[bro[tabIndex]->pageNow]=url;
			bro[tabIndex]->pageNow+=1;
		}else {
			bro[tabIndex]->url[bro[tabIndex]->pageNow]=url;
			bro[tabIndex]->pageNow+=1;
		}
		
		bro[tabIndex]->pages+=1;	
}

string Browser::GetUrl(int tabIndex) {
	return  bro[tabIndex]->pageNow==0? bro[tabIndex]->url[bro[tabIndex]->pageNow] : bro[tabIndex]->url[bro[tabIndex]->pageNow-1];
}

void Browser::GoBack(int tabIndex) {
	if(bro[tabIndex]->pageNow>1){
		bro[tabIndex]->pageNow-=1;
	}else{
		bro[tabIndex]->url[bro[tabIndex]->pageNow-1]="";
	}
	
}

void Browser::GoForward(int tabIndex) {
	if(bro[tabIndex]->url[bro[tabIndex]->pageNow]!="")
		bro[tabIndex]->pageNow+=1;
}
