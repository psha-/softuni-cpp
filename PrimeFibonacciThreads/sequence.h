#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "element.h"
#include <stdexcept>
#include <memory>

// Abstract sequence class. Encapsulates a current element and a method to calculate next element.

class Sequence
{
public:
    Sequence(Element* current);

    virtual void calculateNext() throw(std::out_of_range) = 0;

    inline void setCurrent(Element* current)
    {
        m_Current = std::shared_ptr<Element>(current);
    }

    inline std::shared_ptr<Element> getCurrent() const
    {
        return m_Current;
    }

protected:
    std::shared_ptr<Element> m_Current;

};

#endif // SEQUENCE_H
