#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "gameobject.h"
#include "vec2.h"

// Something that has mass and velocity
class RigidBody : public GameObject
{
public:
    RigidBody(unsigned int id, float mass);

    inline void setMass(float mass)
    {
        m_Mass = mass;
    }

    inline float getMass() const
    {
        return m_Mass;
    }

    inline void addForceOverTime(Vec2 force, float time=1)
    {
        m_Velocity += force * time / m_Mass;
    }

    inline void setVelocity(Vec2 velocity)
    {
        m_Velocity = velocity;
    }

    inline Vec2 getVelocity() const
    {
        return m_Velocity;
    }

protected:
    float m_Mass;
    // Velocity is in m/s (SI), not km/h!
    Vec2 m_Velocity;
};

#endif // RIGIDBODY_H
