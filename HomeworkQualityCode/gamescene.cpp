#include "gamescene.h"

GameScene::GameScene(GameEnvironment* environment)
    :m_Environment(environment)
{
}

// Deletes the pointers, because the design is that the scene owns the environment and the objects.
GameScene::~GameScene()
{
    delete m_Environment;
    for(auto it = m_Objects.begin(); it != m_Objects.end(); it++) {
        delete it->second;
    }
}
