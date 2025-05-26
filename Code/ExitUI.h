#ifndef EXITUI_H
#define EXITUI_H

#include "Exit.h"
using namespace std;

class Exit;

class ExitUI{
    private:
        Exit* exitcontroller;
    public:
        ExitUI(Exit* controller) : exitcontroller(controller) {}
        void startUI();
        void doExit();
};

#endif