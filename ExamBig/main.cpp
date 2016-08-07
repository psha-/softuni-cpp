// Asparuh Krastev
// asparuh.k

#include <iostream>
#include "landingsitecontainer.h"

using namespace std;

int main()
{

    LandingSiteContainer landingSites = LandingSiteContainer();

    LandingSite capeCanaveral = LandingSite();
    capeCanaveral.m_Name = "CapeCanaveral";
    capeCanaveral.m_Type = LOCATION_TYPE_GROUND;
    capeCanaveral.landingAttemptsCount = 10;

    landingSites.addLandingSite(capeCanaveral);

    Mission* spaceX = new Mission();
    spaceX->m_Name = "SpaceX";
    spaceX->payloadWeight = 100000;

    Mission* spaceY = new Mission();
    spaceY->m_Name = "SpaceY";
    spaceY->payloadWeight = 200000;

    landingSites.addMission("CapeCanaveral", spaceX);
    landingSites.addMission("CapeCanaveral", spaceY);

    landingSites.printMissionByName("SpaceY");

    return 0;
}

