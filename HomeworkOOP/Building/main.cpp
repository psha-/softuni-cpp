#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Company {
public:
    Company(string name, unsigned int officeCount, unsigned int employeeCount, unsigned int vacanciesCount);
    ~Company();
    inline unsigned int getOfficeCount() const
    {
        return m_officeCount;
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
    unsigned int m_officeCount;
    unsigned int m_employeeCount;
    unsigned int m_vacanciesCount;
};

Company::Company(string name, unsigned int officeCount=0, unsigned int employeeCount=0, unsigned int vacanciesCount=0)
{
    m_name = name;
    m_officeCount = officeCount;
    m_employeeCount = employeeCount;
    m_vacanciesCount = vacanciesCount;
}

Company::~Company()
{
}



class Building {
public:
    Building(string name, unsigned int floorsNumber, vector<Company> companies);
    ~Building();

    inline string getName() const
    {
        return m_name;
    }
    unsigned int getEmployeeCount() const;
    unsigned int getVacanciesCount() const;
    unsigned int getSeatCount() const;
    unsigned int getOfficeCount() const;

    inline float getEmployeesVsSeats() const
    {
        return getEmployeeCount() / getSeatCount();
    }
    inline float getEmployeesPerFloor() const
    {
        return getEmployeeCount() / m_floorsNumber;
    }
    inline float getOfficesPerFloor() const
    {
        return getOfficeCount() / m_floorsNumber;
    }
    inline float getEmployeesPerOffice() const
    {
        return getEmployeeCount() / getOfficeCount();
    }

private:
    string m_name;
    unsigned int m_floorsNumber;
    vector<Company> m_companies;

};

Building::Building(string name, unsigned int floorsNumber, vector<Company> companies)
{
    m_name = name;
    m_floorsNumber = floorsNumber;
    m_companies = companies;
}

Building::~Building()
{
}

unsigned int Building::getEmployeeCount() const
{
    unsigned int count = 0;
    for(size_t i=0; i<m_companies.size(); i++) {
        count += m_companies[i].getEmployeeCount();
    }
    return count;
}

unsigned int Building::getVacanciesCount() const
{
    unsigned int count = 0;
    for(size_t i=0; i<m_companies.size(); i++) {
        count += m_companies[i].getVacanciesCount();
    }
    return count;
}

unsigned int Building::getSeatCount() const
{
    unsigned int count = 0;
    for(size_t i=0; i<m_companies.size(); i++) {
        count += m_companies[i].getSeatCount();
    }
    return count;
}

unsigned int Building::getOfficeCount() const
{
    unsigned int count = 0;
    for(size_t i=0; i<m_companies.size(); i++) {
        count += m_companies[i].getOfficeCount();
    }
    return count;
}

bool EmployeeCmp(Building a,Building b) { return a.getEmployeeCount()<b.getEmployeeCount(); }

bool VacanciesCmp(Building a,Building b) { return a.getVacanciesCount()<b.getVacanciesCount(); }

bool HighestEmployessVsSeatsCmp(Building a,Building b) { return a.getEmployeesVsSeats()<b.getEmployeesVsSeats(); }

bool MostEmployeePerFloorCmp(Building a,Building b) { return a.getEmployeesPerFloor()<b.getEmployeesPerFloor(); }

bool MostOfficesPerFloorCmp(Building a,Building b) { return a.getOfficesPerFloor()<b.getOfficesPerFloor(); }

bool MostEmployeePerOfficeCmp(Building a,Building b) { return a.getEmployeesPerOffice()<b.getEmployeesPerOffice(); }


int main()
{
    vector<Building> businessPark = {
        Building("XYZ industries", 6, {Company("XYZ industries", 127, 600, 196)}),
        Building("Rapid development crew", 8, {Company("Rapid development crew", 210, 822, 85), Company("Restaurant")}),
        Building("Softuni", 11, {Company("Softuni", 106, 200, 60)}),
    };

    cout << "Most employees: " << max_element(businessPark.begin(), businessPark.end(), EmployeeCmp)->getName() << endl;
    cout << "Most free places: " << max_element(businessPark.begin(), businessPark.end(), VacanciesCmp)->getName() << endl;
    cout << "Highest coefficient employees/(employees + free seats): " << max_element(businessPark.begin(), businessPark.end(), HighestEmployessVsSeatsCmp)->getName() << endl;
    cout << "Most people per floor: " << max_element(businessPark.begin(), businessPark.end(), MostEmployeePerFloorCmp)->getName() << endl;
    cout << "Least people per floor: " << min_element(businessPark.begin(), businessPark.end(), MostEmployeePerFloorCmp)->getName() << endl;
    cout << "Most offices per floor: " << max_element(businessPark.begin(), businessPark.end(), MostOfficesPerFloorCmp)->getName() << endl;
    cout << "Least offices per floor: " << min_element(businessPark.begin(), businessPark.end(), MostOfficesPerFloorCmp)->getName() << endl;
    cout << "Most people per floor: " << max_element(businessPark.begin(), businessPark.end(), MostEmployeePerOfficeCmp)->getName() << endl;
    cout << "Least people per floor: " << min_element(businessPark.begin(), businessPark.end(), MostEmployeePerOfficeCmp)->getName() << endl;
    return 0;
}

