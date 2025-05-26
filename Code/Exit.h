#ifndef EXIT_H
#define EXIT_H

#include "ExitUI.h"
#include "FileManager.h"
using namespace std;

class ExitUI;

class Exit{
    private:
        ExitUI* exitUI;
        FileManager* filemanager;
    public:
        Exit(FileManager* filemanager);
        void executeExit();
};

#endif