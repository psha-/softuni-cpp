#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace cashdesk {

class Item
{
public:
    Item(std::string name, std::string sku, float);

    Item(const Item&);

    inline float getValue() const
    {
        return m_Value;
    }

    inline void setValue( float value )
    {
        m_Value = value;
    }

    inline std::string getName() const
    {
        return m_Name;
    }
    inline std::string getSKU() const
    {
        return m_SKU;
    }

private:
    std::string m_Name;
    std::string m_SKU;
    float m_Value;
};

}

#endif // ITEM_H
