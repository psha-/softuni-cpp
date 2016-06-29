#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

#include "gameobject.h"
#include "personalized.h"

class GameEnvironment : public GameObject, public Personalized
{
public:
    GameEnvironment(unsigned int id, std::string name, float gravity);

    inline float getGravity() const
    {
        return m_Gravity;
    }

private:
    float m_Gravity;
};

#endif // GAMEENVIRONMENT_H
