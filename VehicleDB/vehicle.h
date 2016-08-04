#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "date.h"
#include "person.h"


class Vehicle
{
public:
    Vehicle(std::string plate,
            float weight,
            unsigned short int seatCount,
            std::string chassisId,
            std::string engineId,
            Person owner,
            Date initialRegistration,
            Date currentRegistration);

    // Inline members. They have to be in the .h file
    inline std::string getPlate() const
    {
        return m_Plate;
    }

    inline float getWeight() const
    {
        return m_Weight;
    }

    inline unsigned short int getSeatCount() const
    {
        return m_SeatCount;
    }

    inline std::string getChassisId() const
    {
        return m_ChassisId;
    }

    inline std::string getEngineId() const
    {
        return m_EngineId;
    }

    inline Person getOwner() const
    {
        return m_Owner;
    }

    inline Date getInitialRegistration() const
    {
        return m_InitialRegistration;
    }

    inline Date getCurrentRegistration() const
    {
        return m_CurrentRegistration;
    }

protected:
    std::string m_Plate;
    float m_Weight;
    unsigned short int m_SeatCount;
    std::string m_ChassisId;
    std::string m_EngineId;
    Person m_Owner;
    Date m_InitialRegistration;
    Date m_CurrentRegistration;

};

#endif // VEHICLE_H
