#ifndef Browser_Included
#define Browser_Included

#include "console.h"
using namespace std;

class Browser {
	public: 
		Browser();
		void NewTab();
		void CloseTab(int tabIndex);
		int Size();
		void GoToPage(int tabIndex, string url);
		string GetUrl(int tabIndex);
		void GoBack(int tabIndex);
		void GoForward(int tabIndex);

	private:
		//TODO: 
		int size;
		int maxSize;
		int sizePage;
		struct B {
			string *url;
			int pages;
			int pageNow;

		};
		B** bro;

};

#endif;
