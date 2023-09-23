//
// Created by Matteo Annunziata on 21/07/2023.
//

#ifndef MATTEOANNUNZIATA_PROGETTOLABORATORIO_USER_H
#define MATTEOANNUNZIATA_PROGETTOLABORATORIO_USER_H

#include "ShoppingList.h"
#include "Observer.h"
#include <iostream>


using namespace std;

class User : public Observer {
public:

    ~User() override {
        for (auto &itr : myLists)            // utilizzo la sintassi semplificata del range-for per iterare su tutti gli elementi
            itr.second->unsubscribe(this); // sicuramente dovró disiscrivermi dalla lista quando viene cancellato l'utente
    }

    void update(const string &listName) override;

    void addShoppingList(const ShoppingList shoppingList);

    void removeShoppingList(const string &name);

    const map<string, shared_ptr<ShoppingList>> &getMyLists() const;

private:
    map<string, shared_ptr<ShoppingList>> myLists; // le liste sono i subject; un User puó avere piú subject
};


#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_USER_H
