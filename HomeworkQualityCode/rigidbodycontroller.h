#ifndef RIGIDBODYCONTROLLER_H
#define RIGIDBODYCONTROLLER_H

#include "gamescene.h"
#include "rigidbody.h"

// Controls a rigid body object
class RigidBodyController
{
public:
    RigidBodyController(GameScene* scene, RigidBody* object);

    inline RigidBody* getRigidBody() const
    {
        return m_RigidBody;
    }

protected:
    GameScene* m_Scene;
    RigidBody* m_RigidBody;
};

#endif // RIGIDBODYCONTROLLER_H
