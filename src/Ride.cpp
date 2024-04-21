class Ride {
public:
    int rideID;
    int riderID;
    int driverID;
    Location startLocation;
    Location endLocation;
    std::string status;
    double ETA;

    Ride(int id, int riderID, Location start, Location end)
        : rideID(id), riderID(riderID), startLocation(start), endLocation(end), status("pending"), ETA(0) {}

    void assignDriver(int driverID) {
        this->driverID = driverID;
        status = "assigned";
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }

    void updateETA(double time) {
        ETA = time;
    }
};

