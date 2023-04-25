#include "Browser.h"
#include <iostream>
Browser::Browser(){
	size =0;
	capacity=10;
	tabs = new Tab*[capacity];

}
void Browser::resize(){
	capacity*=2;
	Tab** nTabs = new Tab*[capacity];
	for(int i=0; i<size; i++){
		nTabs[i]=tabs[i];
	}
	delete[] tabs;
	tabs=nTabs;

}

void Browser::NewTab(){
	if(size==capacity) {
		resize();
	}
	Tab * newTab= new Tab ();
	newTab->url= "";
	newTab->next=NULL;
	newTab->prev=NULL;
	tabs[size]=newTab;
	size++;
	

}

void Browser::CloseTab(int tabIndex){
	for(int i=tabIndex+1; i<size ; i++){
		tabs[i-1]=tabs[i];
	}
	size--;
	
}

int Browser::Size() {
	return size;
}

void Browser::GoToPage(int tabIndex, string url) {
	Tab * curr= tabs[tabIndex];
	Tab * newTab =  new Tab ();
	newTab->url=url;
	newTab->next=NULL;
	newTab->prev=curr;
	curr->next=newTab;

	tabs[tabIndex]=newTab;

}

string Browser::GetUrl(int tabIndex) {
	return tabs[tabIndex]->url;
}

void Browser::GoBack(int tabIndex) {
	if(tabs[tabIndex]->prev){
		 tabs[tabIndex]= tabs[tabIndex]->prev;
	}
}

void Browser::GoForward(int tabIndex) {
	if(tabs[tabIndex]->next){
		tabs[tabIndex]=tabs[tabIndex]->next;
	}

}