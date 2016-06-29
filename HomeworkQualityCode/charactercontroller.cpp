#include "charactercontroller.h"

CharacterController::CharacterController(GameScene* scene, GameCharacter* character)
    :RigidBodyController(scene, character)
{
}

float CharacterController::calculateObjectMaxJumpHeight() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;
    float jumpTime = calculateAirborneTime() / 2;
    // v0 * t / 2
    return initialJumpVelocity * jumpTime / 2;
}

float CharacterController::calculateAirborneTime() const
{
    float initialJumpVelocity = m_RigidBody->getVelocity().y;
    float gravityAcceleration = m_Scene->getEnvironment()->getGravity();

    // (v0 - v)/a * 2, where v=0
    return initialJumpVelocity/gravityAcceleration * 2;
}

bool CharacterController::canObjectJumpAtHeight(float height) const
{
    return height < calculateObjectMaxJumpHeight();
}
