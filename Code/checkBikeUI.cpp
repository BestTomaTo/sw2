#include "checkBikeUI.h"
using namespace std;

void checkBikeUI::startUI() {
    this->checkBikeList();
}

void checkBikeUI::checkBikeList() {
    checkrentcontroller->showBikeInfo();
}