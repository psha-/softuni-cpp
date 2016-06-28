#include "item.h"
#include "iostream"

using namespace cashdesk;

Item::Item(std::string name, std::string sku, float value)
    :m_Name(name), m_SKU(sku), m_Value(value)
{
}

Item::Item(const Item& item)
    :m_Name(item.m_Name), m_SKU(item.m_SKU), m_Value(item.m_Value)
{
    std::cout << "Copied Item " << m_Name << std::endl;
}
