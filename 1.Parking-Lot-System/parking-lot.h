#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#include <string>
#include <vector>
#include <mutex>

//Enum for vehicle types
enum VehicleType
{
    CAR,
    MOTORCYCLE,
    TRUCK
};

// Vehicle class
class Vehicle
{
public:
    std::string licensePlate;
    VehicleType type;

    Vehicle(std::string plate, VehicleType vehicleType);
};

// ParkingSpot class
class ParkingSpot
{
public:
    int spotNumber;
    VehicleType allowedType;
    bool isOccupied;
    Vehicle* parkedVehicle;

    ParkingSpot(int number, VehicleType type);
    bool park(Vehicle* vehicle);
    Vehicle* retrieve();
};

// ParkingLevel class
class ParkingLevel
{
private:
    std::vector<ParkingSpot> spots;

public:
    ParkingLevel(int numberOfSpots, VehicleType type);
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* retrieveVehicle(int spotNumber);
    void getAvailableSpots();
};

// ParkingLot class
class ParkingLot
{
private:
    std::vector<ParkingLevel> levels;
    std::mutex mtx; // Mutex for thread safety;

public:
    ParkingLot(int numberOfLevels, int spotsPerLevel);
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* retrieveVehicle(int levelNumber, int spotNumber);
    void getAvailableSpots();
};

#endif // PARKING_LOT_H