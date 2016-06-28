#include "purchase.h"

using namespace cashdesk;

Purchase::Purchase(POS *pos)
    :m_POS(pos), m_Amount(0), m_Total(0)
{
}

void Purchase::addItem(const Item& item)
{
    auto it = m_Items.find(item.getSKU());
    if( it != m_Items.end() ) {
        ++it->second.count;
        m_Total += it->second.item.getValue();
    }
    else {
        m_Items.insert(std::make_pair(item.getSKU(), ItemCollection(item)));
        m_Total += item.getValue();
    }
}

bool Purchase::editItemValue(std::string sku, float value)
{
    auto it = m_Items.find(sku);
    if( it != m_Items.end() ) {
        // Recalculate Total.
        m_Total -= it->second.item.getValue() * it->second.count;
        it->second.item.setValue(value);
        m_Total += value * it->second.count;
        return true;
    }
    return false;
}
