#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "rigidbodycontroller.h"
#include "gamecharacter.h"
#include "gamescene.h"
#include "vec2.h"

class CharacterController : public RigidBodyController
{
public:
    CharacterController(GameScene* scene, GameCharacter* character);

    inline GameCharacter* getGameCharacter() const
    {
        return static_cast<GameCharacter*>(m_RigidBody);
    }

    inline void jump()
    {
        // To jump, apply character jump force for 1sec to y.
        m_RigidBody->addForceOverTime(Vec2(0, getGameCharacter()->getJumpForce()), 1);
    }

    float calculateJumpHeight() const;

    float calculateAirborneTime() const;

    bool canJumpAtHeight(float) const;

};

#endif // CHARACTERCONTROLLER_H
