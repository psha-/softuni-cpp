#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "gameobject.h"
#include "gameenvironment.h"
#include <unordered_map>

class GameScene
{
public:
    GameScene(GameEnvironment* environment);

    inline void setEnvironment(GameEnvironment* environment)
    {
        m_Environment = environment;
    }

    inline GameEnvironment* getEnvironment() const
    {
        return m_Environment;
    }

    inline void addObject(GameObject* object)
    {
        m_Objects.insert(std::make_pair(object->getId(), object));
    }

    inline GameObject* getObjectById(unsigned int id)
    {
        return m_Objects[id];
    }

    ~GameScene();

private:
    GameEnvironment* m_Environment;
    std::unordered_map<unsigned int, GameObject*> m_Objects;

};

#endif // GAMESCENE_H
