
#include "vehiclefactory.hpp"
#include "bike.hpp"
#include "car.hpp"

Vehicle* vehicleFactory::getVehicle(string s){
    Vehicle *v;
    if(s=="bike"){
        v=new Bike();
    }else if(s=="car"){
        v=new Car();
    }
    return v;
}

