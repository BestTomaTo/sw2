#include <string>
#include "EnrollUI.h"
#include "MemberCollection.h"
#include "BikeCollection.h"
using namespace std;

class Enroll {
    private:
        EnrollUI* enrollUI;
        MemberCollection* MemCollPointer;
        BikeCollection* BikeCollPointer;
    public:
        Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection);
        void addNewBike(string bikeid, string bikename);
};