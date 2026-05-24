#include<iostream>
#include "vehiclefactory.hpp"
using namespace std;

int main(){
    string s;
    cin>>s;
    Vehicle* myvehicle=vehicleFactory::getVehicle(s);
    myvehicle->createvehicle();
}