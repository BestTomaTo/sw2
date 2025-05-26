#ifndef CHECKBIKEUI_H
#define CHECKBIKEUI_H

#include "checkBike.h"
using namespace std;

class checkBike;

class checkBikeUI{
    private:
        checkBike* checkrentcontroller;
    public:
        checkBikeUI(checkBike* controller) : checkrentcontroller(controller) {}
        void startUI();
        void checkBikeList();
};

#endif