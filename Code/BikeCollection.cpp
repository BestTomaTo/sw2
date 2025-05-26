#include <string>
#include "BikeCollection.h"
using namespace std;

BikeCollection::BikeCollection(FileManager* filemanager) {
    BikeArray = new Bike[100];
    this->filemanager = filemanager;
}

void BikeCollection::addNewBike(string bikeid, string bikename){
    ofstream& out_fp = filemanager->getOutputStream();
    BikeArray[cnt++] = Bike(bikeid, bikename);
    out_fp << "> " << bikeid << " " << bikename << endl;
}

Bike* BikeCollection::getBike(string bikeid) {
    for (int i=0; i<cnt; i++) {
        if (BikeArray[i].getBikeID() == bikeid) {        
            return &BikeArray[i];
        }
    }
    return NULL;
}