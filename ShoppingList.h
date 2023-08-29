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

    void removeItem(const string &name);

    void setBought(const string &name);

    int notBought();

    const string &getShoppingListName() const;

    void setShoppingListName(const string &shoppingListName);

    const map<string, shared_ptr<Item>> &getShoppingList() const;

    const list<Observer *> &getObservers() const;

    const map<string, int> &getCategories() const;

private:
    list<Observer *> observers;
    map<string, shared_ptr<Item>> shoppingList;
    map<string, int> categories;                // posso usare questa mappa per tenere traccia del numero di oggetti per ogni categoria
    string shoppingListName;
};


#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_SHOPPINGLIST_H
