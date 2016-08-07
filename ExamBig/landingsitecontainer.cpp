#include "landingsitecontainer.h"
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

std::mutex LandingSiteContainer::m_containerMutex;

LandingSiteContainer::LandingSiteContainer()
{
}

void LandingSiteContainer::addLandingSite(LandingSite landingSite)
{
    if(m_landingSites.find(landingSite.m_Name) == m_landingSites.end()) {
        m_landingSites.insert(std::pair<std::string, LandingSite>(landingSite.m_Name, landingSite));
    }
}


void LandingSiteContainer::addMission(std::string landingSiteName, Mission* mission)
{
    // First thing - make sure always to hand over the pointer to the resource manager.
    std::shared_ptr<Mission> pMission = std::shared_ptr<Mission>(mission);
    if(m_landingSites.find(landingSiteName) == m_landingSites.end()) {
        std::cout << "Landing site does not exist" << std::endl;
        return;
    }
    m_containerMutex.lock();
    m_landingSites[landingSiteName].addMission(pMission);
    SortMissionsByName(m_landingSites[landingSiteName]);
    m_containerMutex.unlock();
}

void LandingSiteContainer::SortMissionsByName(LandingSite& landingSite)
{
    std::sort(landingSite.m_landingSuccessMissions.begin(), landingSite.m_landingSuccessMissions.end(),
              [](const std::shared_ptr<Mission> & a, const std::shared_ptr<Mission> & b) -> bool
    {
        if(a.get()->launchDateTime.m_Year.m_Val < b.get()->launchDateTime.m_Year.m_Val &&
                a.get()->launchDateTime.m_Month.m_Val < b.get()->launchDateTime.m_Month.m_Val &&
                a.get()->launchDateTime.m_Day.m_Val < b.get()->launchDateTime.m_Day.m_Val
                ) {
            return true;
        }
        return false;
    });
}

void LandingSiteContainer::printMissionByName(std::string name)
{
    std::vector<std::thread> threads = std::vector<std::thread>();
    std::shared_ptr<Mission> foundMission = nullptr;

    // Start search in threads and wait for them to finish
    for(auto ls_it = m_landingSites.begin(); ls_it != m_landingSites.end(); ls_it++) {
        threads.push_back(std::thread(&LandingSiteContainer::searchForMissionByName, this, ls_it->second, name, std::ref(foundMission)));
    }
    for(auto thread_it = threads.begin(); thread_it != threads.end(); thread_it++) {
        thread_it->join();
    }

    // TODO: Print all data
    if(foundMission != nullptr) {
        std::cout << foundMission.get()->m_Name;
    }
}

void LandingSiteContainer::searchForMissionByName(LandingSite site, std::string name, std::shared_ptr<Mission>& foundMission)
{
    if(foundMission != nullptr) {
        // Mission is already fond in another thread. Stop searching.
        return;
    }
    m_containerMutex.lock();
    for(auto it=site.m_landingSuccessMissions.begin(); it!=site.m_landingSuccessMissions.end(); it++ )
    {
        if(it->get()->m_Name == name) {
            foundMission = *it;
            return;
        }
    }
    m_containerMutex.unlock();
}
