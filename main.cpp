#include <iostream>
#include <string>
#include "ShoppingList.h"
#include "User.h"

int main() {

    map<string, ShoppingList> shoppingLists;
    map<string, Item> items;
    map<string, User> users;

    while (true) {
        cout << "1. Crea nuovo utente" << endl;
        cout << "2. Crea una nuova lista" << endl;
        cout << "3. Crea un nuovo oggetto" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username;
            cout << "Inserisci il nome dell'utente: " << endl;
            cin >> username;
            User u;
            users.insert(make_pair(username, u));
            cout << "Utente creato: " << username << endl;
        } else if (choice == 2) {
            cout << "Seleziona l'utente: " << endl;
            for (const auto &pair : users) {
                cout << "- " << pair.first << endl;
            }
            string username;
            cin >> username;
            auto userIt = users.find(username);
            if (userIt == users.end()) {
                cout << "Utente non trovato. " << endl;
                continue;
            }
            string listName;
            cout << "Inserisci il nome della lista: " << endl;
            cin >> listName;
            userIt->second.addShoppingList(
                    ShoppingList(listName)); // aggiungo la nuova lista della spesa all'utente corrispondente
            shoppingLists.insert(
                    make_pair(listName, ShoppingList(listName)));  // aggiungo la nuova lista alla mappa delle liste
            cout << "Nuova lista creata per l'utente: " << username << endl;
        } else if (choice == 3) {
            cout << "Seleziona l'utente:" << endl;
            for (const auto &pair : users);
            cout << "- " << pair.first << endl;
        }
        string username;
        cin >> username;
        auto userIt = users.find(username);
        if (userIt == users.end()) {
            cout << "Utente non trovato." << endl;
            continue;
        }
        cout << "Inserisci il nome dell'oggetto: ";
        string itemName;
        cin >> itemName;
        cout << "Inserisci la quantitá: " << endl;
        int quantity;
        cin >> quantity;

        string category;
        cout << "Inserisci la categoria dell'oggetto: " << endl;
        cin >> category;

        items.insert(make_pair(itemName, Item(itemName, category, quantity)));

    }
}


return 0;
}
