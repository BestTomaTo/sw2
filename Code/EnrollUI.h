#ifndef ENROLLUI_H
#define ENROLLUI_H

#include "Enroll.h"
#include "FileManager.h"
using namespace std;

class Enroll;

class EnrollUI {
    private:
        Enroll* enrollcontroller;
        FileManager* filemanager;
    public:
        EnrollUI(Enroll* controller, FileManager* filemanager) : enrollcontroller(controller), filemanager(filemanager) {}
        void startUI();
        void insertBikeInfo();
};

#endif