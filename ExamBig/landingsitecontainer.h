#ifndef LANDINGSITECONTAINER_H
#define LANDINGSITECONTAINER_H

#include "landingsite.h"
#include <map>
#include <string>
#include <memory>
#include <mutex>

class LandingSiteContainer
{
public:
    LandingSiteContainer();

    void addLandingSite(LandingSite landingSite);
    void addMission(std::string landingSiteName, Mission* mission);

    // Used in multithreading
    void searchForMissionByName(LandingSite site, std::string name, std::shared_ptr<Mission>& foundMission);

    void printMissionByName(std::string);

private:
    std::map<std::string, LandingSite> m_landingSites;
    static std::mutex m_containerMutex;

    void SortMissionsByName(LandingSite& landingSite);

};

#endif // LANDINGSITECONTAINER_H
