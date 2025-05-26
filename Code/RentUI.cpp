#include "RentUI.h"
using namespace std;

void RentUI::startUI() {
    this->rentBike();
}

void RentUI::rentBike() {
    rentcontroller->createRent();
}