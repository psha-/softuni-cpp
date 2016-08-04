#include "vehicledatabase.h"
#include <iostream>

VehicleDatabase::VehicleDatabase()
    :m_Cars(),m_Trucks(), m_Motorcycles()
{
}

VehicleDatabase::~VehicleDatabase()
{
    for(auto it=m_Cars.begin(); it!=m_Cars.end(); it++) {
        delete *it;
    }
    for(auto it=m_Trucks.begin(); it!=m_Trucks.end(); it++) {
        delete *it;
    }
    for(auto it=m_Motorcycles.begin(); it!=m_Motorcycles.end(); it++) {
        delete *it;
    }

    m_Cars.clear();
    m_Trucks.clear();
    m_Motorcycles.clear();
    delete m_FoundVehicle;
}

// Searches a given vehicle container one element at a time in different threads and stops on success. Honestly I was puzzled how to do this with for_each.
void VehicleDatabase::searchVehicles(const std::vector<Vehicle*>& vehicle, size_t current, std::function<bool(Vehicle*)> callback)
{
    while(current < vehicle.size() && m_FoundVehicle==nullptr) {
        if(callback(vehicle[current])) {
            m_FoundVehicle = vehicle[current];
        }
        current++;
    }
}

void VehicleDatabase::search(std::function<bool(Vehicle*)> callback, std::function<void(Vehicle*)> success)
{
    size_t currentCar = 0;
    size_t currentTruck = 0;
    size_t currentMotorcycle = 0;
    m_FoundVehicle = nullptr;

    std::thread carSearch (&VehicleDatabase::searchVehicles, this, m_Cars, currentCar, callback);
    std::thread truckSearch (&VehicleDatabase::searchVehicles, this, m_Trucks, currentTruck, callback);
    std::thread motorcyclesSearch (&VehicleDatabase::searchVehicles, this, m_Motorcycles, currentMotorcycle, callback);

    carSearch.join();
    truckSearch.join();
    motorcyclesSearch.join();

    if(m_FoundVehicle!=nullptr) {
        success(m_FoundVehicle);
    }
    else {
        std::cout << "Not found" << std::endl;
    }
}
