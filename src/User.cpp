#include <string>

class User {
public:
    int userID;
    std::string name;
    std::string email;

    User(int id, std::string name, std::string email) : userID(id), name(name), email(email) {}

    void requestRide(const Location& startLocation, const Location& endLocation);
    void rateDriver(int rating, int rideID);
};

