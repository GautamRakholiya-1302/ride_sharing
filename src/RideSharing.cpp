#include <iostream>
#include <vector>

class RideSharing {
private:
    std::vector<User*> users;
    std::vector<Driver*> drivers;
    std::vector<Ride*> rides;
    RideMatchingSystem rideMatchingSystem;

public:
    // Add user to the system
    void addUser(User* user) {
        users.push_back(user);
    }

    // Add driver to the system
    void addDriver(Driver* driver) {
        drivers.push_back(driver);
        rideMatchingSystem.addDriver(driver);
    }

    // Request a ride from a user
    void requestRide(User* user, const Location& start, const Location& end) {
        // Create a new ride
        int newRideID = rides.size() + 1;
        Ride* newRide = new Ride(newRideID, user->userID, start, end);
        rides.push_back(newRide);

        // Find the closest available driver
        Driver* assignedDriver = rideMatchingSystem.findClosestDriver(*newRide);
        if (assignedDriver) {
            newRide->assignDriver(assignedDriver->driverID);
            assignedDriver->acceptRide(newRide->rideID);
            std::cout << "Ride assigned to Driver ID: " << assignedDriver->driverID << std::endl;
        } else {
            std::cout << "No available drivers at the moment." << std::endl;
        }
    }

    // Complete a ride
    void completeRide(Driver* driver, Ride* ride) {
        driver->completeRide(ride->rideID);
        ride->updateStatus("completed");
        std::cout << "Ride completed: Ride ID " << ride->rideID << std::endl;
    }
};

