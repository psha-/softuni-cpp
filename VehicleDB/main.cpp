#include <iostream>
#include "vehicledatabase.h"
#include "vehicle.h"
#include "car.h"
#include "motorcycle.h"
#include "truck.h"
#include "date.h"
#include "person.h"
#include <string>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.m_Day.m_Val << "/" << date.m_Month.m_Val << "/" << date.m_Year.m_Val;

    return os;
}

int main()
{
    VehicleDatabase vehicles = VehicleDatabase();

    vehicles.addCar(new Car(Vehicle("CA1234EB", 2.1f, 4, "12ASD46FDGD434", "1234567", Person("Petar Simeonov"), Date(Day(1), Month(3), Year(1990)), Date(Day(12), Month(7), Year(2014)))));
    vehicles.addCar(new Car(Vehicle("CA1234EE", 2.1f, 4, "12ASD46FDGD434", "1234567", Person("Petar Simeonov"), Date(Day(1), Month(3), Year(1990)), Date(Day(12), Month(7), Year(2014)))));
    vehicles.addMotorcycle(new Motorcycle(Vehicle("CA8755EE", 0.5f, 1, "66ADFS54334", "77776543", Person("Grigor Grigorov"), Date(Day(3), Month(7), Year(1999)), Date(Day(11), Month(8), Year(2013)))));
    vehicles.addTruck(new Truck(Vehicle("EB6743AE", 4.4f, 2, "87SDF234DFSSF342", "6655434", Person("Mihail Ivonov"), Date(Day(7), Month(11), Year(1980)), Date(Day(10), Month(2), Year(2005)))));

    std::string plate;

    auto success = [](Vehicle* vehicle) {
        cout << "Weight: " << vehicle->getWeight() << "t" << endl;
        cout << "Number of seats: " << vehicle->getSeatCount() << endl;
        cout << "Chassis number: " << vehicle->getChassisId() << endl;
        cout << "Engine number: " << vehicle->getEngineId() << endl;
        cout << "Owner: " << vehicle->getOwner() << endl;
        cout << "Date of first registration: " << vehicle->getInitialRegistration() << endl;
        cout << "Date of registration in country: " << vehicle->getCurrentRegistration() << endl;
    };

    cout << "Enter registration number to search" << endl << ">>";
    cin >> plate;
    cout << "Searching..." << endl;

    auto searchByPlate = [=](Vehicle* vehicle)->bool {
        if(vehicle->getPlate() == plate) {
            return true;
        }
        return false;
    };

    vehicles.search(searchByPlate, success);

    return 0;
}

