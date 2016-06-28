#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "item.h"
#include "pos.h"
#include "purchase.h"

using namespace std;
using namespace cashdesk;

namespace cashdesk {

unordered_map<string, Item*> Items;

Item* findItem(string sku)
{
    auto foundItem = Items.find(sku);
    if( foundItem == Items.end() ) {
        cout << "Item cannot be found" << endl;
        return nullptr;
    }
    return foundItem->second;
}

ostream& operator<<(ostream& os, const POS& pos)
{
    cout << pos.getName() << endl;
    cout << "BIC: " << pos.getBIC() << endl;
    cout << "Address: " << pos.getAddress();
    return os;
}

ostream& operator<<(ostream& os, const Purchase& purchase)
{
    cout << *purchase.getPOS() << endl;
    cout << "Purchases: " << purchase.getTotal() << " leva" << endl;
    cout << "Given: " << purchase.getAmount() << endl;
    cout << "Change: " << fixed << setprecision(2) << purchase.calcChange();
    return os;
}

const Purchase& operator+=(Purchase& purchase, const Item& item)
{
    // I prefer class member instead of friend function. I would not use += operator. It doesn't make sense. What about +, -, ..?
    purchase.addItem(item);
    return purchase;
}

enum Menu {
    HELP = 'h',
    CLEAR = 'c',
    TOTAL = 't',
    CHECKOUT = 'g',
    EDIT_ITEM = 'e',
    INFO = 'i',
    EXIT = 'x',
};

ostream& operator<<(ostream& os, const Menu& option)
{
    os << (char)toupper(option) << ", " << (char)option;
    return os;
}

}

int main()
{
    Items = {
        {"tb11111111", new Item("Tooth brush", "tb11111111", 1.29)},
        {"tp12345678", new Item("Toilet paper", "tp12345678", 0.50)},
        {"sp00000001", new Item("Slippers", "sp00000001", 5.00)},
        {"sw12345678", new Item("Star wars T-Shirt", "sw12345678", 19.99)},
    };
    POS* chinaCity = new POS("China City", "12345678", "Somewhere in the middle of nowhere");

    Purchase currentPurchase(chinaCity);

    while(true) {
        cout << "Enter choice. " << HELP << " for help." << endl << "> ";
        string choice;
        getline (cin, choice);
        if( choice.length() > 1 ) {
            Item* item = findItem(choice);
            if( item != nullptr ) {
                currentPurchase += *item;
            }
            continue;
        }
        switch(tolower(choice[0])) {
        case CLEAR:
            currentPurchase.clearItems();
            cout << "Purchase cleared." << endl;
            break;
        case TOTAL:
            cout << "Total: " << currentPurchase.getTotal() << endl;
            break;
        case CHECKOUT:
            float amount;
            cout << "Please enter the amount of money: ";
            cin >> amount;
            cin.ignore();
            currentPurchase.setAmount(amount);
            cout << "The change is: " << fixed << setprecision(2) << currentPurchase.calcChange() << " leva" << endl;
            break;
        case EDIT_ITEM:
            {
                string sku;
                float value;
                cout << "Enter item sku: ";
                getline (cin, sku);
                cout << "Enter new price: ";
                cin >> value;
                cin.ignore();
                if( !currentPurchase.editItemValue(sku, value) ) {
                    cout << "Item doesn't exist in purchase" << endl;
                }
                break;
            }
        case INFO:
            cout << currentPurchase << endl;
            break;
        case EXIT:
            return 0;
        case HELP:
        default:
            cout << HELP << ": Help" << endl;
            cout << CLEAR << ": Clear purchase" << endl;
            cout << TOTAL << ": Display total" << endl;
            cout << CHECKOUT << ": Checkout / Calculate total" << endl;
            cout << EDIT_ITEM << ": Change item price" << endl;
            cout << INFO << ": Display purchase info" << endl;
            cout << EXIT << ": Exit" << endl;
            break;
        }
    }
    return 0;
}

