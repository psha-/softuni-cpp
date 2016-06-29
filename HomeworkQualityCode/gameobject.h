#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Base class for all elements in the game.
// In future it can have position.
class GameObject
{
public:
    GameObject(unsigned int id);

    inline void setId(unsigned int id)
    {
        m_Id = id;
    }

    inline unsigned int getId() const
    {
        return m_Id;
    }

protected:
    unsigned int m_Id;
};

#endif // GAMEOBJECT_H
