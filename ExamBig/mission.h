#ifndef MISSION_H
#define MISSION_H

#include <string>
#include "datetime.h"
#include "geocoordinates.h"


class Mission
{
public:
    Mission();

    inline double getPayloadWeightInPounds() const
    {
        return payloadWeight * 2.20462262;
    }

    std::string m_Name;
    std::string m_VehileName;
    DateTime launchDateTime;
    DateTime landDateTime;
    double payloadWeight;
    unsigned long flightDurationInSeconds; // Can store more than 100 years.
    bool m_IsLanded;
    GeoCoordinates landingCoordinates;

};

#endif // MISSION_H
