#include "charactercontroller.h"
#include <cmath>

CharacterController::CharacterController(GameScene* scene, GameCharacter* character)
    :RigidBodyController(scene, character)
{
}

float CharacterController::calculateObjectJumpHeight() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;
    float gravityAcceleration = m_Scene->getEnvironment()->getGravity();

    // h = (v^2 - v0^2) / 2 * a , where v=0
    return pow(initialJumpVelocity, 2) / 2 / gravityAcceleration;
}

float CharacterController::calculateAirborneTime() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;

    // t/2 = (2 * h) / (v0 + v), where v=0
    return 4 * calculateObjectJumpHeight() / initialJumpVelocity;
}

bool CharacterController::canObjectJumpAtHeight(float height) const
{
    return height < calculateObjectJumpHeight();
}
