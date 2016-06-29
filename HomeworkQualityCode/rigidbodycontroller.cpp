#include "rigidbodycontroller.h"
#include "gamescene.h"

RigidBodyController::RigidBodyController(GameScene* scene, RigidBody* object)
    :m_Scene(scene), m_RigidBody(object)
{
}
