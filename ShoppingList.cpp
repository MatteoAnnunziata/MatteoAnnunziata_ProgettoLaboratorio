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

void ShoppingList::addItem(const Item &item) {

    auto it = shoppingList.find(item.getItemName());

    // controllo se l'oggetto é giá presente nella lista
    if (it != shoppingList.end() && it->second->getCategory() == item.getCategory()) {
        // l'oggetto é giá presente nella lista e appartiene alla stessa categoria
        int res = it->second->getItemQuantity() + item.getItemQuantity();
        it->second->setItemQuantity(res);
    } else {
        // l'oggetto non é presente nella lista o appartiene ad una categoria diversa
        auto ipt = make_shared<Item>(item);
        shoppingList.insert(make_pair(item.getItemName(), ipt));
    }

    // notifico agli osservatori ( utenti ) che la lista é stata aggiornata
    notify();
}

void ShoppingList::removeItem(const string &name) {
    auto itn = shoppingList.find(name);

    //controllo se l'oggetto con il nome specificato é presente nella lista
    if (itn == shoppingList.end()) {
        throw std::invalid_argument("Nome non trovato");
    } else {
        // cerco l'elemento nella mappa delle categorie
        auto it = categories.find(itn->second->getCategory());
        // se lo trovo decremento il contatore delle categorie
        it->second--;
        // se il contatore é a zero, rimuovo l'elemento dalla mappa delle categorie
        if (it->second == 0)
            categories.erase(it);

        // imposto la quantitá dell'oggetto a zero
        itn->second->setItemQuantity(0);
        // rimuovo l'oggetto dalla mappa della lista della spesa
        shoppingList.erase(itn);

        // notifico gli osservatori ( utenti ) che la lista é stata aggiornata
        notify();
    }
}

void ShoppingList::setBought(const string &name) {
    auto it = shoppingList.find(name);

    // verifico se l'oggetto con il nome specificato é presente nella lista
    if (it != shoppingList.end()) {
        bool isBought = it->second->isBought();

        // inverto lo stato "acquistato" dell'oggetto
        it->second->setBought(!isBought);

        // notifico gli osservatori (utenti) che la lista é stata aggiornata
        notify();
    } else
        throw std::invalid_argument("Nome non trovato");    // se non trovo l'oggetto lancio un'eccezione
}

// metodo per visualizzare il numero degli oggetti ancora da acquistare
int ShoppingList::notBought() {
    int res = 0;    // inizializzo il risultato a zero

    // itero attraverso ogni elemento nella mappa shoppingList
    for (auto &it : shoppingList) {
        // controllo se l'oggetto non é stato ancora acquistato
        if (!it.second->isBought()) {
            //aggiungo la quantitá dell'oggetto al risulatato
            res += it.second->getItemQuantity();
        }
    }
    return res; // Restituisce la somma delle quantità degli oggetti che non sono ancora stati acquistati
}
