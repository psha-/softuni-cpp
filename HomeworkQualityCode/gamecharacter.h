#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include "rigidbody.h"
#include "personalized.h"

class GameCharacter : public RigidBody, public Personalized
{
public:
    GameCharacter(unsigned int id, std::string name, float mass, float jumpForce=250);

    inline void setJumpForce(float jumpForce)
    {
        m_JumpForce = jumpForce;
    }

    inline float getJumpForce() const
    {
        return m_JumpForce;
    }

private:
    float m_JumpForce;
};

#endif // GAMECHARACTER_H
