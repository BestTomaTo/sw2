#include "Rent.h"
using namespace std;

class RentUI {
    private:
        Rent* rentcontroller;
    public:
        RentUI(Rent* controller) : rentcontroller(controller) {}
        void startUI();
        void rentBike();
};