#include "vehicle.hh"

Vehicle::Vehicle(){
    printf("Vehicle\n");    
}

Vehicle::~Vehicle(){
    printf("~Vehicle\n");    
}

Vehicle& Vehicle::operator=(const Vehicle &other){
    printf("Copy Vehicle\n");
    fuel = other.fuel;    
    return *this;
}

FlyingVehicle::FlyingVehicle(){
    printf("Flying Vehicle\n");
}

FlyingVehicle::~FlyingVehicle(){
    printf("~Flying Vehicle\n");
}

Helicopter::Helicopter(){
    printf("Helicopter\n");
}

Helicopter::~Helicopter(){
    printf("~Helicopter\n");
}

Helicopter& Helicopter::operator=(const Helicopter &other) {
    printf("Copy helicopter\n");
    Vehicle::operator=(other);
    propellers = other.propellers;
    return *this;
}