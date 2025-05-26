#include "Exit.h"
using namespace std;

class ExitUI{
    private:
        Exit* exitcontroller;
    public:
        ExitUI(Exit* controller) : exitcontroller(controller) {}
        void startUI();
        void doExit();
};