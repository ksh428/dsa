#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
//FACTORY DESIGN MODEL
//client uses the factory to create the product and dont need to take care of the implementation
class Vehicle{
      public:
      virtual void createVehicle()=0;
};
class Bike:public Vehicle{
      public:
      void createVehicle(){
            cout<<"Bike Created!!"<<endl;
      }
};

class Car:public Vehicle{
      public:
      void createVehicle(){
            cout<<"Car created"<<endl;
      }
};

class VehicleFactory{
      public:
      static Vehicle* getVehicle(string vehicleType){
            Vehicle* vehicle;
            if(vehicleType=="car"){
                  vehicle=new Car();
            }else if(vehicleType=="bike"){
                  vehicle=new Bike();
            }
            return vehicle;
      }
};


int main(){
     string vehicleType;
     cin>>vehicleType;
     Vehicle* vehicle=VehicleFactory::getVehicle(vehicleType);
     vehicle->createVehicle();
}
