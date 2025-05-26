#include "Exit.h"
using namespace std;

Exit::Exit() {
    exitUI = new ExitUI(this);
    exitUI->startUI();
}

void Exit::executeExit() {
cout << "debug" << endl;
    out_fp << "6.1 종료" << endl;
}