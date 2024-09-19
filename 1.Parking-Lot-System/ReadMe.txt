#Requirements:

The parking lot should have multiple levels, each level with a certain number of parking spots.
The parking lot should support different types of vehicles, such as cars, motorcycles, and trucks.
Each parking spot should be able to accommodate a specific type of vehicle.
The system should assign a parking spot to a vehicle upon entry and release it when the vehicle exits.
The system should track the availability of parking spots and provide real-time information to customers.
The system should handle multiple entry and exit points and support concurrent access.


--------------------------------------------------------------------------------------------------------------

#Compilation: 

g++ -o parking_lot main.cpp parking-lot.cpp
./parking_lot

--------------------------------------------------------------------------------------------------------------

Steps-by-step Approach:

1. Understand the Requirements:
   - Identify functional Requirements
   - Identify non-functional Requirements

2. Clarify Ambiguities

3. Create a High-Level Design
   - Identify Major Components
   - Define Relationships

4. Create Class Design

5. Implement Functions

6 Consider design paterns and principles

7. Implementation

8. Testing and edge cases


----------------------------------------------------------------------------------------------------------------

#Step-by-Step Approach:

1. Understand the Requirements

    Identify Functional Requirements:

    Multiple levels in the parking lot.
    Different types of vehicles (car, motorcycle, truck).
    Specific parking spots for each vehicle type.
    Parking assignment and retrieval processes.
    Real-time availability tracking.
    Support for multiple entry and exit points.
    Identify Non-Functional Requirements:

    Concurrency support for simultaneous vehicle entries/exits.
    Scalability for potential future enhancements.
    Maintainability of the code.

2. Clarify Ambiguities

    Ask clarifying questions about specific requirements:
    How many vehicles can fit in a spot?
    How should the system handle cases where no spots are available?
    Should we handle time limits for parking?
    Are there any constraints on parking assignments (e.g., trucks must go to larger spots)?

3. Create a High-Level Design

    Identify Major Components:

    Vehicle Class: To represent vehicles (license plate, type).
    ParkingSpot Class: To manage individual parking spots (status, allowed vehicle type).
    ParkingLevel Class: To manage multiple parking spots on a level.
    ParkingLot Class: To manage multiple levels and overall parking operations.

Define Relationships:

    ParkingLot contains multiple ParkingLevels.
    Each ParkingLevel contains multiple ParkingSpots.
    ParkingSpot is associated with a Vehicle.

4. Create Class Design

    Define attributes and methods for each class:
    Vehicle: licensePlate, type; methods can be constructors or getters.
    ParkingSpot: spotNumber, allowedType, isOccupied, methods like park(), retrieve().
    ParkingLevel: A collection of ParkingSpots; methods for parking and retrieving vehicles.
    ParkingLot: A collection of ParkingLevels; methods for overall parking management and spot availability.

5. Implement Functions

    Start with the core functionalities:
    Implement the park() method in ParkingSpot, checking if the spot is available and if the vehicle type matches.
    Implement the retrieve() method to free up the spot.
    Implement methods in ParkingLevel and ParkingLot to handle the interactions between these classes.

6. Consider Design Patterns and Principles

    Design Patterns:

    Factory Pattern: If you want to create vehicles based on input type.
    Singleton Pattern: If your parking lot should only have one instance.
    Observer Pattern: For notifying users about parking availability (if needed).
    SOLID Principles:

    Single Responsibility: Each class should have one responsibility.
    Open/Closed Principle: Classes should be open for extension but closed for modification.
    Liskov Substitution: Subtypes should be substitutable for their base types.
    Interface Segregation: Use specific interfaces rather than a general-purpose one.
    Dependency Inversion: High-level modules should not depend on low-level modules directly.

7. Implementation

    Write the code for the classes and methods defined earlier.
    Use appropriate data structures (e.g., vectors, maps) for storing vehicles and parking spots.

8. Testing and Edge Cases

    Test your implementation with different scenarios:
    Parking and retrieving vehicles of different types.
    Attempting to park when the lot is full.
    Retrieving from invalid spots.
    Concurrent access handling (if applicable).

9. Review and Optimize

    After implementing, review your design:
    Are there any areas that can be simplified?
    Can the code be made more efficient?
    Is the code readable and maintainable?