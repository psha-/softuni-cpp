#include "charactercontroller.h"
#include <cmath>

CharacterController::CharacterController(GameScene* scene, GameCharacter* character)
    :RigidBodyController(scene, character)
{
}

float CharacterController::calculateJumpHeight() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;
    float gravityAcceleration = m_Scene->getEnvironment()->getGravity();

    // h = (v^2 - v0^2) / 2 * a , where v=0
    float jumpHeight = pow(initialJumpVelocity, 2) / 2 / gravityAcceleration;

    return jumpHeight;
}

float CharacterController::calculateAirborneTime() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;

    // t/2 = (2 * h) / (v0 + v), where v=0
    float airborneTime = 2 * 2 * calculateJumpHeight() / initialJumpVelocity;

    return airborneTime;
}

bool CharacterController::canJumpAtHeight(float height) const
{
    return height < calculateJumpHeight();
}
