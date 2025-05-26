#include <string>
#include "EnrollUI.h"
using namespace std;

void EnrollUI::startUI() {
    this->insertBikeInfo();
}

void EnrollUI::insertBikeInfo() {
    string bikeid, bikename;
    in_fp >> bikeid >> bikename;
    enrollcontroller->addNewBike(bikeid, bikename);
}