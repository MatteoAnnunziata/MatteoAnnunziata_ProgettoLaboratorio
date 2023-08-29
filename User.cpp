//
// Created by Matteo Annunziata on 21/07/2023.
//

#include "User.h"

void User::update(const string &listName) {
    auto itr = myLists.find(
            listName);      // con questo cerco un elemento all'interno del contenitore associativo ( map ) e otterró un iteratore per accedere all'elemento o per verificare se é stato trovato
    cout << "Lista ' " << listName << " ' aggiornata: " << endl;
}

void User::addShoppingList(ShoppingList shoppingList) {
    auto ptrList = make_shared<ShoppingList>(
            shoppingList);     // sto creando un puntatore condiviso chiamato ptrList che punta a una nuova istanza della classe ShoppingLis. La nuova istanza é una copia dell'oggetto shoppingList passato alla funzione
    myLists.insert(make_pair(shoppingList.getShoppingListName(),
                             ptrList));     // inserisco una nuova coppia nel contenitore myLists
    shoppingList.subscribe(
            this);       // mi iscrivo alla lista di interessati a ricevere notifiche quando di verificano modifiche
}

void User::removeShoppingList(const string &name) {
    auto itr = myLists.find(name);
    if (itr == myLists.end()) {
        throw std::invalid_argument("Invalid shopping list name");
    } else {
        itr->second->unsubscribe(this);
        myLists.erase(name);
    }
}

const map<string, shared_ptr<ShoppingList>> &User::getMyLists() const {
    return myLists;
}
