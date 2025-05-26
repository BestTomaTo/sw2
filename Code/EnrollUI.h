#include "Enroll.h"
using namespace std;

class EnrollUI {
    private:
        Enroll* enrollcontroller;
    public:
        EnrollUI(Enroll* controller) : enrollcontroller(controller) {}
        void startUI();
        void insertBikeInfo();
};