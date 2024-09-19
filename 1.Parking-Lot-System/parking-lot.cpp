#include "parking-lot.h"
#include <iostream>

//////////////////////////////// Vehicle methods ////////////////////////////////

// vehicle class construtor
Vehicle::Vehicle(std::string plate, VehicleType vehicleType) : licensePlate(plate), type(vehicleType) {}


//////////////////////////////// ParkingSpot methods ////////////////////////////////

//ParkingSpot class constructor
ParkingSpot::ParkingSpot(int number, VehicleType type) : spotNumber(number), allowedType(type), isOccupied(false), parkedVehicle(nullptr) {}

// Park a vehicle in the spot
bool ParkingSpot::park(Vehicle* vehicle) 
{
    if(!isOccupied && vehicle->type == allowedType)
    {
        parkedVehicle = vehicle;
        isOccupied = true;
        return true;
    }
    return false;
}

// Retrieve the vehicle from the spot
Vehicle* ParkingSpot::retrieve() 
{
    if(isOccupied)
    {
        Vehicle* temp = parkedVehicle;
        isOccupied = false;
        parkedVehicle = nullptr;
        return temp;
    }
    return nullptr;
}


//////////////////////////////// ParkingLevel methods //////////////////////////////// 

// ParkingLevel class constructor
ParkingLevel::ParkingLevel(int numberOfSpots, VehicleType type) 
{
    for(int i = 0; i < numberOfSpots; i++)
    {
        ParkingSpot spot(i + 1, type);
        spots.push_back(spot);
    }
}

// Park a vehicle in this level
bool ParkingLevel::parkVehicle(Vehicle* vehicle) 
{
    for(auto& spot : spots)
    {
        if(spot.park(vehicle))
        {
            std::cout << "Vehicle " << vehicle->licensePlate << " parked at spot " << spot.spotNumber << " (Level)" <<  std::endl;
            return true;
        }
    }
    return false;
}

// Retrieve a vehicle from the specified spot
Vehicle* ParkingLevel::retrieveVehicle(int spotNumber) 
{
    if(spotNumber > 0 && spotNumber <= spots.size())
    {
        Vehicle* vehicle = spots[spotNumber - 1].retrieve();
        if(vehicle)
        {
            std::cout << "Vehicle " << vehicle->licensePlate << " retrieve from spot " << spotNumber << std::endl;
            return vehicle;
        }
        std::cout << "No vehicle found at spot " << spotNumber << std::endl;
    }
    else
    {
        std::cout << "Invalid spot number!" << std::endl;
    }
    return nullptr;
}

// Get available spots in this level
void ParkingLevel::getAvailableSpots() 
{
    std::cout << "Available spots in this level: ";
    for(const auto& spot : spots)
    {
        if(!spot.isOccupied)
            std::cout << spot.spotNumber << " ";
    }
    std::cout << std::endl;
}


//////////////////////////////// ParkingLot methods ////////////////////////////////

// ParkingLevel class constructor
ParkingLot::ParkingLot(int numberOfLevels, int spotsPerLevel) 
{
    for(int i = 0; i < numberOfLevels; i++)
    {
        ParkingLevel level(spotsPerLevel, (i % 3 == 0) ? CAR : (i % 3 == 1) ? MOTORCYCLE : TRUCK);
        levels.push_back(level);
    }
}

// Park a vehicle in the parking lot
bool ParkingLot::parkVehicle(Vehicle* vehicle) 
{
    std::lock_guard<std::mutex> lock(mtx); //lock the mutex for thread safely

    for(auto& level : levels)
    {
        if(level.parkVehicle(vehicle))
            return true;
    }
    std::cout << "No available spots for vehicle " << vehicle->licensePlate << std::endl;
    return false;
}

// Retrieve a vehicle from a specified lvel and spot
Vehicle* ParkingLot::retrieveVehicle(int levelNumber, int spotNumber) 
{
    std::lock_guard<std::mutex> lock(mtx); //lock the mutex

    if(levelNumber > 0 && levelNumber <= levels.size())
    {
        return levels[levelNumber - 1].retrieveVehicle(spotNumber);
    }
    std::cout << "Invalid level number!" << std::endl;
    return nullptr;
}

// Get available spots in the parking lot
void ParkingLot::getAvailableSpots() 
{
    for(int i = 0; i < levels.size(); i++)
    {
        std::cout << "Level " << (i + 1) << ": ";
        levels[i].getAvailableSpots();
    }
} 