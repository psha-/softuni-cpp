#ifndef PURCHASE_H
#define PURCHASE_H

#include "pos.h"
#include "item.h"
#include <unordered_map>

namespace cashdesk {

struct ItemCollection {
    // Calling Item copy constructor.
    // Keep a copy of Item to be able to change its price only in a purchase later on.
    ItemCollection(const Item& _item, unsigned int _count=1)
        :item(_item), count(_count)
    {
    }
    Item item;
    unsigned int count;
};

class Purchase
{
public:
    Purchase(POS *);

    inline float getAmount() const
    {
        return m_Amount;
    }

    inline void setAmount(float amount)
    {
        m_Amount = amount;
    }

    inline float calcChange() const
    {
        return m_Amount - m_Total;
    }

    inline POS* getPOS() const
    {
        return m_POS;
    }

    inline void clearItems()
    {
        m_Items.clear();
        m_Total = 0;
    }

    inline float getTotal() const
    {
        return m_Total;
    }

    bool editItemValue(std::string sku, float value);

    void addItem(const Item&);

private:
    POS* m_POS;
    float m_Amount;
    float m_Total;
    std::unordered_map<std::string, ItemCollection> m_Items;
};

}

#endif // PURCHASE_H
