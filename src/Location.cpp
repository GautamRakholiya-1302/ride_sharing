class Location {
public:
    double latitude;
    double longitude;

    Location(double lat, double lon) : latitude(lat), longitude(lon) {}

    double calculateDistance(const Location& other) const {
        // Simplistic distance calculation (not accurate for real-world scenarios)
        return sqrt(pow(latitude - other.latitude, 2) + pow(longitude - other.longitude, 2));
    }
};

