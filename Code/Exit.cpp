#include "Exit.h"
using namespace std;

Exit::Exit(FileManager* filemanager) {
    exitUI = new ExitUI(this);
    this->filemanager = filemanager;
    exitUI->startUI();
}

void Exit::executeExit() {
    ofstream& out_fp = filemanager->getOutputStream();
    
    out_fp << "6.1 종료" << endl;
}