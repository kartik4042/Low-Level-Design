#include <iostream>
#include "parking-lot.h"

int main()
{
    //Create a parking lot with 2 levels and 5 spots per level
    ParkingLot parkingLot(2, 5);

    //Create some vehicles
    Vehicle car1("ABC123", CAR);
    Vehicle motorcycle1("XYZ456", MOTORCYCLE);
    Vehicle truck1("LMN789", TRUCK);

    // Park Vehicle
    parkingLot.parkVehicle(&car1);
    parkingLot.parkVehicle(&motorcycle1);
    parkingLot.parkVehicle(&truck1);

    //Show available spots
    parkingLot.getAvailableSpots();

    //Retrieve a vehicle
    parkingLot.retrieveVehicle(1, 1);
    parkingLot.retrieveVehicle(2, 1);

    //Show avaiable spots again
    parkingLot.getAvailableSpots();

    return 0;
}