//
// Created by Matteo Annunziata on 21/07/2023.
//

#ifndef MATTEOANNUNZIATA_PROGETTOLABORATORIO_SHOPPINGLIST_H
#define MATTEOANNUNZIATA_PROGETTOLABORATORIO_SHOPPINGLIST_H

#include <vector>
#include <map>
#include <list>
#include <stdexcept>
#include "Item.h"
#include "Subject.h"
#include "Observer.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const string &shoppingListName) : shoppingListName(shoppingListName) {}

    ~ShoppingList() override = default;

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    void addItem(const Item &item);

    void removeItem(const string &name, int quantityToRemove = 1);

    void setBought(const string &name);

    int notBought() const;

    const string &getShoppingListName() const;

    void setShoppingListName(const string &shoppingListName);

    int getTotalItems() const;

    shared_ptr<Item> findItem(const string &itemName);

    const list<Observer *> &getObservers() const;

    void print() const;

private:
    list<Observer *> observers;
    map<string, shared_ptr<Item>> shoppingList;
    string shoppingListName;
};


#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_SHOPPINGLIST_H
