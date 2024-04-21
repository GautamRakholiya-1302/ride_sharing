class Driver {
public:
    int driverID;
    std::string name;
    bool isAvailable;
    Location currentLocation;

    Driver(int id, std::string name, Location location) : driverID(id), name(name), currentLocation(location), isAvailable(true) {}

    void updateLocation(const Location& newLocation) {
        currentLocation = newLocation;
    }

    void acceptRide(int rideID);
    void completeRide(int rideID);
};

