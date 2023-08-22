//
// Created by Matteo Annunziata on 21/07/2023.
//

#include "ShoppingList.h"

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notify() {
    for (auto &itr : observers)
        itr->update(shoppingListName);
}

const string &ShoppingList::getShoppingListName() const {
    return shoppingListName;
}

void ShoppingList::setShoppingListName(const string &shoppingListName) {
    ShoppingList::shoppingListName = shoppingListName;
}

const map<string, shared_ptr<Item>> &ShoppingList::getShoppingList() const {
    return shoppingList;
}

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}

const map<string, int> &ShoppingList::getCategories() const {
    return categories;
}
