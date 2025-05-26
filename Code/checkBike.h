#include "checkBikeUI.h"
#include "MemberCollection.h"
#include "RentalCollection.h"
using namespace std;

class checkBike{
    private:
        checkBikeUI* checkbikeUI;
        MemberCollection* MemCollPointer;
        RentalCollection* RentCollPointer;
    public:
        checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection);
        void showBikeInfo();
};