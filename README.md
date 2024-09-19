# Parking Lot Management System

---

## **Overview:**
Welcome to the **Parking Lot Management System**! This project is designed to simulate a parking lot with multiple levels and diverse vehicle types. It efficiently manages parking assignments, availability tracking, and ensures smooth vehicle entry and exit.

---

## **Requirements:**
- The parking lot should have multiple levels, each with a certain number of parking spots.
- The system must support different types of vehicles, including cars, motorcycles, and trucks.
- Each parking spot should accommodate a specific type of vehicle.
- The system should assign parking spots upon vehicle entry and release them when vehicles exit.
- Real-time tracking of parking spot availability is essential for customer information.
- The system should handle multiple entry and exit points while supporting concurrent access.

---

## **Workflow:**
1. **Vehicle Entry**: Check for available spots and assign a suitable parking spot based on vehicle type.
2. **Spot Occupancy Tracking**: Update the status of the parking spot to occupied.
3. **Vehicle Exit**: Release the parking spot and update its status.
4. **Real-Time Updates**: Provide current availability status to users.
5. **Concurrency Handling**: Manage simultaneous entries and exits efficiently.

---

## **Steps-by-Step Approach:**

### 1. **Understand the Requirements:**
   - **Functional Requirements:**
     - Multiple levels in the parking lot.
     - Support for various vehicle types (car, motorcycle, truck).
     - Real-time availability tracking.
   - **Non-Functional Requirements:**
     - Concurrency support for simultaneous vehicle entries/exits.
     - Scalability and maintainability of the code.

### 2. **Clarify Ambiguities:**
   - Ask key questions:
     - How many vehicles can fit in a spot?
     - What happens when no spots are available?
     - Are there time limits for parking?
     - Any constraints on parking assignments (e.g., larger vehicles in specific spots)?

### 3. **Create a High-Level Design:**
   - **Major Components:**
     - **Vehicle Class**: Represents vehicles with attributes like license plate and type.
     - **ParkingSpot Class**: Manages individual parking spots (status, allowed vehicle type).
     - **ParkingLevel Class**: Handles multiple parking spots on a level.
     - **ParkingLot Class**: Manages multiple levels and overall parking operations.
   - **Relationships**:
     - ParkingLot contains multiple ParkingLevels.
     - Each ParkingLevel contains multiple ParkingSpots.

### 4. **Create Class Design:**
   - **Classes & Attributes:**
     - **Vehicle**: `licensePlate`, `type`
     - **ParkingSpot**: `spotNumber`, `allowedType`, `isOccupied`
     - **ParkingLevel**: Collection of `ParkingSpots`
     - **ParkingLot**: Collection of `ParkingLevels`
   - **Key Methods**:
     - `park()`: Assign a vehicle to a spot.
     - `retrieve()`: Free up a spot.

### 5. **Implement Functions:**
   - Core functionalities:
     - Implement methods in each class to manage parking and retrieval processes.

### 6. **Consider Design Patterns and Principles:**
   - **Design Patterns:**
     - **Factory Pattern**: For vehicle creation based on input type.
     - **Singleton Pattern**: Ensure only one instance of the parking lot exists.
   - **SOLID Principles**:
     - Each class should adhere to principles like Single Responsibility and Open/Closed.

### 7. **Implementation:**
   - Write the code for classes and methods.
   - Utilize appropriate data structures (e.g., vectors, maps) for managing vehicles and spots.

### 8. **Testing and Edge Cases:**
   - Test various scenarios, including:
     - Parking and retrieving vehicles of different types.
     - Handling full parking situations.
     - Invalid spot retrieval attempts.

### 9. **Review and Optimize:**
   - After implementation, evaluate the design for:
     - Simplification opportunities.
     - Efficiency improvements.
     - Code readability and maintainability.

---

## **Object and Function Lists:**

### **Object List:**
- **Vehicle**
- **ParkingSpot**
- **ParkingLevel**
- **ParkingLot**

### **Function List:**
- `Vehicle::Vehicle(licensePlate, type)`
- `ParkingSpot::park(vehicle)`
- `ParkingSpot::retrieve()`
- `ParkingLevel::addSpot(spot)`
- `ParkingLot::assignSpot(vehicle)`
- `ParkingLot::checkAvailability()`

---

## **Conclusion:**
This Parking Lot Management System is a robust solution that demonstrates essential programming concepts and object-oriented design principles. It's a perfect project for enhancing your understanding of system design and coding practices.

Feel free to explore, contribute, and provide feedback!

---
© [Kartik Kamepalli], [2024]. All rights reserved.
