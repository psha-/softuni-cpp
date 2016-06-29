#include "gamecharacter.h"

GameCharacter::GameCharacter(unsigned int id, std::string name, float mass, float jumpForce)
    :RigidBody(id, mass), Personalized(name), m_JumpForce(jumpForce)
{
}
