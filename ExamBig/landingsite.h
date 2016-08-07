#ifndef LANDINGSITE_H
#define LANDINGSITE_H

#include <string>
#include "locationtype.h"
#include <vector>
#include <memory>
#include "mission.h"

class LandingSite
{
public:
    LandingSite();

    inline void addMission(std::shared_ptr<Mission> mission)
    {
        m_landingSuccessMissions.push_back(mission);
    }

    unsigned int getLandingSuccessAttemptsCount() const
    {
        return m_landingSuccessMissions.size();
    }

    std::string m_Name;
    LocationType m_Type;
    unsigned int landingAttemptsCount;

    // Shared pointer is ussed, because this makes sure the memory is freed up when missions objects are returned to the outside world.
    std::vector<std::shared_ptr<Mission>> m_landingSuccessMissions;

};

#endif // LANDINGSITE_H
