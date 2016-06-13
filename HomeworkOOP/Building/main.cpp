#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Company {
public:
    Company(const string& name, unsigned int employeeCount, unsigned int vacanciesCount)
        :m_name(name),m_employeeCount(employeeCount), m_vacanciesCount(vacanciesCount)
    {}

    inline string getName() const
    {
        return m_name;
    }
    inline unsigned int getEmployeeCount() const
    {
        return m_employeeCount;
    }
    inline unsigned int getVacanciesCount() const
    {
        return m_vacanciesCount;
    }
    inline unsigned int getSeatCount() const
    {
        return m_employeeCount + m_vacanciesCount;
    }

private:
    string m_name;
    unsigned int m_employeeCount;
    unsigned int m_vacanciesCount;
};


class Floor {
public:
    Floor(unsigned int officeCount=0)
        :m_officeCount(officeCount)
    {}

    unsigned int getOfficeCount() const {
        return m_officeCount;
    }

private:
    unsigned int m_officeCount;
};


class Building {
public:
    Building(const Company& company, const vector<Floor>& floors)
        :m_company(company),m_floors(floors)
    {}
    ~Building();

    unsigned int getOfficeCount() const;

    inline string getCompanyName() const
    {
        return m_company.getName();
    }
    inline unsigned int getEmployeeCount() const
    {
        return m_company.getEmployeeCount();
    }
    inline unsigned int getVacanciesCount() const
    {
        return m_company.getVacanciesCount();
    }
    inline unsigned int getSeatCount() const
    {
        return m_company.getSeatCount();
    }
    inline float getEmployeesVsSeats() const
    {
        return (float)getEmployeeCount() / getSeatCount();
    }
    inline float getEmployeesPerFloor() const
    {
        return (float)getEmployeeCount() / m_floors.size();
    }
    inline float getOfficesPerFloor() const
    {
        return (float)getOfficeCount() / m_floors.size();
    }
    inline float getEmployeesPerOffice() const
    {
        return (float)getEmployeeCount() / getOfficeCount();
    }

private:
    Company m_company;
    vector<Floor> m_floors;
};

Building::~Building()
{
}

unsigned int Building::getOfficeCount() const
{
    unsigned int count = 0;
    for(size_t i=0; i<m_floors.size(); i++) {
        count += m_floors[i].getOfficeCount();
    }
    return count;
}

bool EmployeeCmp(Building a,Building b) { return a.getEmployeeCount()<b.getEmployeeCount(); }

bool VacanciesCmp(Building a,Building b) { return a.getVacanciesCount()<b.getVacanciesCount(); }

bool EmployeesVsSeatsCmp(Building a,Building b) { return a.getEmployeesVsSeats()<b.getEmployeesVsSeats(); }

bool EmployeePerFloorCmp(Building a,Building b) { return a.getEmployeesPerFloor()<b.getEmployeesPerFloor(); }

bool OfficesPerFloorCmp(Building a,Building b) { return a.getOfficesPerFloor()<b.getOfficesPerFloor(); }

bool EmployeePerOfficeCmp(Building a,Building b) { return a.getEmployeesPerOffice()<b.getEmployeesPerOffice(); }


int main()
{
    vector<Building> businessPark = {
        Building(Company("XYZ industries", 600, 196), {
            // 6 floors, 127 offices
            Floor(21),
            Floor(21),
            Floor(21),
            Floor(21),
            Floor(21),
            Floor(22),
        }),
        Building(Company("Rapid development crew", 822, 85), {
            // 8 floors, 210 offices and a restaurant
            Floor(),
            Floor(30),
            Floor(30),
            Floor(30),
            Floor(30),
            Floor(30),
            Floor(30),
            Floor(30),
        }),
        Building(Company("Softuni", 200, 60), {
            // 11 floors, 106 offices
            Floor(10),
            Floor(10),
            Floor(10),
            Floor(10),
            Floor(10),
            Floor(10),
            Floor(10),
            Floor(9),
            Floor(9),
            Floor(9),
            Floor(9),
        }),
    };

    cout << "Most employees: building \"" << max_element(businessPark.begin(), businessPark.end(), EmployeeCmp)->getCompanyName() << "\"" << endl;
    cout << "Most free places: building \"" << max_element(businessPark.begin(), businessPark.end(), VacanciesCmp)->getCompanyName() << "\"" << endl;
    cout << "Highest coefficient employees/(employees + free seats): building \"" << max_element(businessPark.begin(), businessPark.end(), EmployeesVsSeatsCmp)->getCompanyName() << "\"" << endl;
    cout << "Most people per floor: building \"" << max_element(businessPark.begin(), businessPark.end(), EmployeePerFloorCmp)->getCompanyName() << "\"" << endl;
    cout << "Least people per floor: building \"" << min_element(businessPark.begin(), businessPark.end(), EmployeePerFloorCmp)->getCompanyName() << "\"" << endl;
    cout << "Most offices per floor: building \"" << max_element(businessPark.begin(), businessPark.end(), OfficesPerFloorCmp)->getCompanyName() << "\"" << endl;
    cout << "Least offices per floor: building \"" << min_element(businessPark.begin(), businessPark.end(), OfficesPerFloorCmp)->getCompanyName() << "\"" << endl;
    cout << "Most people per office: building \"" << max_element(businessPark.begin(), businessPark.end(), EmployeePerOfficeCmp)->getCompanyName() << "\"" << endl;
    cout << "Least people per office: building \"" << min_element(businessPark.begin(), businessPark.end(), EmployeePerOfficeCmp)->getCompanyName() << "\"" << endl;

    return 0;
}

