#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

struct Stop {
    std::string id;
    std::string stop_name;
    std::string stop_lat;
    std::string stop_lon;
    std::string location_type;
};

struct Route {
    std::string route_id;
    std::vector<Stop> stops;
    std::string agency_id;
    std::string route_short_name;
    std::string route_long_name;
    std::string route_type;
    std::string route_url;

};
struct stop_times{
    std::string trip_id;
    std::string arrival_time;
    std::string departure_time;
    std::string stop_id;
    std::string stop_sequence;
    std::string pickup_type;
    std::string drop_off_type;
};
struct trips {
    std::vector<Route> routes;
    std::string route_id;
    std::string service_id;
    std::string trip_id;
    std::string trip_headsign;
    std::string trip_short_name;
};

std::vector<Stop> readStops(const std::string& stopsFile) {
    std::vector<Stop> stops;

    std::ifstream File(stopsFile);
    if (File.is_open()) {
        std::string line;
        getline(File, line);  // Skip header line

        while (getline(File, line)) {
            std::istringstream iss(line);
            std::string token;
            
            std::string id, stop_name, stop_lat, stop_lon, location_type;
            getline(iss, id, ',');
            getline(iss, stop_name, ',');
            getline(iss, stop_lat, ',');
            getline(iss, stop_lon, ',');
            getline(iss, location_type, ',');

            // Convert latitude and longitude to double
            double latitude = std::stod(stop_lat);
            double longitude = std::stod(stop_lon);

            stops.push_back({id, stop_name, latitude, longitude, location_type});
        }

        File.close();
    }

    return stops;
}

//Similarly we can take inputs for route, stop_times and trips


// Find all direct journeys between source and destination stops
void findDirectJourneys(const Stop& source, const Stop& destination) {
    // Implement code to find direct journeys
}

void findJourneysWithOneTransfer(const Stop& source, const Stop& destination) {
    // Implement code to find journeys with one transfer
}

int main() {

    // Read stops data 
   // readStops(id, stop_name, stop_lat, stop_lon, location_type);
     std::vector<Stop> stops = readStops("ULTRA/paths/stops.txt");

    // Process the stops data as needed
    for (const auto& stop : stops) {
        std::cout << "Stop ID: " << stop.id << ", Name: " << stop.stop_name << "Stop latitude: " << stop.stop_lat << "Stop longitude: " << stop.stop_lon << std::endl;
    }

    //Similarly read all the GFTS data

    
    findDirectJourneys(/* Add necessary parameters */);

    findJourneysWithOneTransfer(/* Add necessary parameters */);

    return 0;
}