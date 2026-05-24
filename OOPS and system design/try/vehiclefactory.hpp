#ifndef vehiclefactory_hpp
#define vehiclefactory_hpp

#include<iostream>
using namespace std;
#include "vehicle.hpp"

class vehicleFactory{
    public:
    static Vehicle* getVehicle(string name);
};

#endif