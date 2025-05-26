#include "ExitUI.h"
using namespace std;

void ExitUI::startUI() {
    this->doExit();
}

void ExitUI::doExit() {
    exitcontroller->executeExit();
}