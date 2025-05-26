#include "checkBike.h"
using namespace std;

class checkBikeUI{
    private:
        checkBike* checkrentcontroller;
    public:
        checkBikeUI(checkBike* controller) : checkrentcontroller(controller) {}
        void startUI();
        void checkBikeList();
};