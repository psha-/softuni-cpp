#ifndef VEHICLEDATABASE_H
#define VEHICLEDATABASE_H

#include <vector>
#include "vehicle.h"
#include "truck.h"
#include "motorcycle.h"
#include "car.h"
#include <thread>

class VehicleDatabase
{
public:
    VehicleDatabase();
    ~VehicleDatabase();

    inline void addCar(Car* car)
    {
        m_Cars.push_back(car);
    }

    inline void addTruck(Truck* truck)
    {
        m_Trucks.push_back(truck);
    }

    inline void addMotorcycle(Motorcycle* motorcycle)
    {
        m_Motorcycles.push_back(motorcycle);
    }

    void searchVehicles(const std::vector<Vehicle*>& vehicle, size_t current, std::function<bool(Vehicle*)> callback);

    void search(std::function<bool(Vehicle*)> callback, std::function<void(Vehicle*)> success);

private:
    Vehicle* m_FoundVehicle;
    std::vector<Vehicle*> m_Cars;
    std::vector<Vehicle*> m_Trucks;
    std::vector<Vehicle*> m_Motorcycles;
};

#endif // VEHICLEDATABASE_H
