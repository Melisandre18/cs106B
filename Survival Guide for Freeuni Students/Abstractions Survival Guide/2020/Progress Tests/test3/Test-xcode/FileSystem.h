//
//  FileSystem.h
//  ProgressTest
//
//  Created by Mikheil on 6/6/20.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include <stdio.h>
#include "console.h"
#include "vector.h"

class FileSystem{
    
public:
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
    // TODO
    //მოიფიქრეთ მოცამთა სტრუქტურა რაშიც შეინახავთ ინფორმაციას
};



#endif /* FileSystem_hpp */
