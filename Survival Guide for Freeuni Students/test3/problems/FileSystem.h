#ifndef FileSystem_Included
#define FileSystem_Included

#include "console.h"
#include "vector.h"

class FileSystem {


public :
	FileSystem();
	string getActiveFolderName();
	Vector<string> getFolderList();
	Vector<string> getFileList();
	bool createFolder(string name);
	bool createFile(string name);
	bool selectFolder(string name);
	void up();
	string searchFile(string fileName);

private:
	//მოიფიქრეთ მოცამთა სტრუქტურა რაშიც შეინახავთ ინფორმაციას
	struct Folder{
		Vector<string>inside;
		Folder* mainF;
		Vector<Folder*>mains;
		string s;
	};
	Folder * curr;
	void find(string &path, string fileName, Folder* now, string pNow);


};

#endif