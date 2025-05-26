#ifndef RENTUI_H
#define RENTUI_H

#include "Rent.h"
using namespace std;

class Rent;

class RentUI {
    private:
        Rent* rentcontroller;
    public:
        RentUI(Rent* controller) : rentcontroller(controller) {}
        void startUI();
        void rentBike();
};

#endif