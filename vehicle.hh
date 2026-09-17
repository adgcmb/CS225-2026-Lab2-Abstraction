#ifndef VEHICLE_HH
#define VEHICLE_HH

#include <stdio.h>

class Vehicle
{
    private:
    int fuel = 0;
    public:
        Vehicle();
        ~Vehicle();
        Vehicle& operator = (const Vehicle &other);
};

class FlyingVehicle : public Vehicle
{
    private:
    int maxAltitude = 0;
    public:
        FlyingVehicle();
        ~FlyingVehicle();
};

class Helicopter : public FlyingVehicle
{
    private:
    int propellers = 2;
    public:
        Helicopter();
        ~Helicopter();
        Helicopter& operator =(const Helicopter &other);
};
#endif