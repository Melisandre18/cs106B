#include "FileSystem.h"

FileSystem::FileSystem() {
	curr= new Folder;
	curr->s="root";
	curr->mainF= curr;
}


string FileSystem::getActiveFolderName() {
	return curr->s;
}

Vector<string> FileSystem::getFolderList() {
	Vector<string> names;
	for(int i=0; i<curr->mains.size(); i++){
		names.add(curr->mains[i]->s);
	}
	return names;
}

Vector<string> FileSystem::getFileList() {
	Vector<string> names;
	for(int i=0; i<curr->inside.size(); i++){
		names.add(curr->inside[i]);
	}
	return names;
}

bool FileSystem::createFolder(string name) {
	for (int i = 0; i < curr->mains.size(); i++) {
		if (curr->mains[i]->s == name) return false;
	}	
	Folder* addNew = new Folder;
	addNew->s= name;
	addNew->mainF = curr;
	curr->mains.add(addNew);
	return true;
}

bool FileSystem::createFile(string name) { 
	for (int i = 0; i < curr->inside.size(); i++) {
		if (curr->inside[i] == name) return false;
	}
	curr->inside.add(name);
	return true;
}

bool FileSystem::selectFolder(string name) { 
	for (int i = 0; i < curr->mains.size(); i++) {
		if (curr->mains[i]->s == name) {
			curr = curr->mains[i];
			return true;
		}
	}
	return false;
}

void FileSystem::up() {
	curr=curr->mainF;
}

string FileSystem::searchFile(string fileName) { 
	string path = "";
	find(path,fileName, curr,  string());
	return path; 
	
}

void FileSystem::find(string &path, string fileName, Folder* now, string pNow){
for (int i = 0; i < now->inside.size(); i++) {
	if (now->inside[i] == fileName){
		path = pNow +  fileName;
		return;
	}
}
	for (int i = 0; i < now->mains.size(); i++) {
		find(path,fileName, now->mains[i],  pNow + now->mains[i]->s + "/");
	}	
}


