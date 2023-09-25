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

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}

void ShoppingList::addItem(const Item &item) {

    auto it = shoppingList.find(item.getItemName());

    // controllo se l'oggetto é giá presente nella lista
    if (it != shoppingList.end() && it->second->getCategory() == item.getCategory()) {
        // l'oggetto é giá presente nella lista e appartiene alla stessa categoria
        int newQuantity = it->second->getItemQuantity() + item.getItemQuantity();
        it->second->setItemQuantity(newQuantity);
    } else {
        // l'oggetto non é presente nella lista o appartiene ad una categoria diversa
        auto newItem = make_shared<Item>(item);
        shoppingList.insert(make_pair(item.getItemName(), newItem));
    }

    // notifico agli osservatori ( utenti ) che la lista é stata aggiornata
    notify();
}

void ShoppingList::removeItem(const string &name, int quantityToRemove) {
    auto itn = shoppingList.find(name);

    //controllo se l'oggetto con il nome specificato é presente nella lista
    if (itn == shoppingList.end()) {
        throw std::invalid_argument("L'oggetto non é presente nella lista.");
    } else {
        //ottengo l'oggetto dalla mappa
        shared_ptr<Item>& item = itn->second;

        //controllo se la quantitá da rimuovere é maggiore o uguale alla quantitá presente
        if(quantityToRemove >= item->getItemQuantity()){
            shoppingList.erase(itn);
        } else{
            item->setItemQuantity(item->getItemQuantity() - quantityToRemove);
        }

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
int ShoppingList::notBought() const{
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

void ShoppingList::print() const {
    cout << "Nome lista: " << shoppingListName << endl << endl;

    cout<< "La lista " << shoppingListName << " contiene " << getTotalItems() << " elementi."<<endl<<endl;

    cout << "Contenuto della lista: " << endl;

    for(const auto& itemPair : shoppingList){
        const string itemName = itemPair.first;
        const shared_ptr<Item>& item = itemPair.second;



        if(item->getItemQuantity() > 0){
            cout <<"Nome prodotto: " << itemName << endl;
            cout<<"Categoria: " << item->getCategory() << endl;
            cout<<"Quantitá: " << item->getItemQuantity() << endl;

            if(item->isBought()){
                cout<< "Stato: Bought" << endl;
            } else{
                cout << "Stato: Not bought" << endl;
            }
            cout<<endl;
        }
    }
}

int ShoppingList::getTotalItems() const {
    int count = 0;
    for(const auto& itemPair : shoppingList){
        const shared_ptr<Item>& item = itemPair.second;
        count += item->getItemQuantity();
    }
    return count;
}

shared_ptr<Item> ShoppingList::findItem(const string &itemName) {
    auto it = shoppingList.find(itemName);
    if(it != shoppingList.end())
        return it->second;
    return nullptr;
}
