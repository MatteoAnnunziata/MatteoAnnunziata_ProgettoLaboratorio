//
// Created by Matteo Annunziata on 21/07/2023.
//

#ifndef MATTEOANNUNZIATA_PROGETTOLABORATORIO_ITEM_H
#define MATTEOANNUNZIATA_PROGETTOLABORATORIO_ITEM_H

#include <iostream>

using namespace std;

class Item {
public:
    Item(string n, string c, int q = 1) : ItemName(n), category(c), ItemQuantity(q) {
    }

    const string &getItemName() const {
        return ItemName;
    }

    const string &getCategory() const {
        return category;
    }

    int getItemQuantity() const {
        return ItemQuantity;
    }

    void setItemQuantity(int itemQuantity) {
        ItemQuantity = itemQuantity;
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool bought) {
        Item::bought = bought;
    }

private:
    string ItemName;
    string category;
    int ItemQuantity;
    bool bought = false;
};


#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_ITEM_H
