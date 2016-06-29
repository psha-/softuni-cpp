#include "gameenvironment.h"

GameEnvironment::GameEnvironment(unsigned int id, std::string name, float gravity)
    :GameObject(id), Personalized(name), m_Gravity(gravity)
{
}
