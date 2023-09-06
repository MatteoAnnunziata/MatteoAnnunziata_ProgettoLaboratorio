#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "ShoppingList.h"
#include "User.h"

using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Aggiungi lista della spesa" << endl;
    cout << "2. Aggiungi oggetto alla lista" << endl;
    cout << "3. Rimuovi oggetto dalla lista" << endl;
    cout << "4. Imposta oggetto come acquistato" << endl;
    cout << "5. Crea utente e unisciti come osservatore a una lista"<<endl;
    cout << "6. Aggiungi una lista ad un osservatore giá esistente " << endl;
    cout << "7. Esci " << endl;
    cout << "Scelta: ";
}

void printAllLists(const map<string, ShoppingList>& lists) {
    for (const auto& listPair : lists) {
        const string& listName = listPair.first;
        const ShoppingList& currentList = listPair.second;

        // cout << "Lista: " << listName << endl;
        currentList.print(); // Chiamiamo il metodo "print" della classe ShoppingList per stampare il contenuto di questa lista
        cout << endl;
    }
}


int main() {
    map<string, ShoppingList> shoppingLists;
    map<string, User> users;

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Inserisci il nome della lista: ";
                string listName;
                cin >> listName;
                ShoppingList newList(listName);

                //Aggiungi la nuova lista direttamente a shoppingLists
                shoppingLists.insert(make_pair(listName, newList));

                cout << "Lista creata con successo." << endl;
                break;
            }
            case 2: {
                cout << "In quale lista vuoi aggiungere l'oggetto? ";
                string listName;
                cin >> listName;

                //  Controlla se la lista esiste in shoppingLists anziché in user
                auto currentListItr = shoppingLists.find(listName);
                if (currentListItr != shoppingLists.end()) {
                    string itemName, itemCategory;
                    int itemQuantity;
                    cout << "Nome dell'oggetto: ";
                    cin >> itemName;
                    cout << "Categoria dell'oggetto: ";
                    cin >> itemCategory;
                    cout << "Quantità dell'oggetto: ";
                    cin >> itemQuantity;

                    Item newItem(itemName, itemCategory, itemQuantity);

                    // Aggiungi l'oggetto alla lista trovata in shoppingLists
                    currentListItr->second.addItem(newItem);

                    cout << "Oggetto aggiunto alla lista con successo." << endl;
                } else {
                    cout << "La lista non esiste." << endl;
                }
                break;
            }
            case 3: {
                cout << "Da quale lista vuoi rimuovere l'oggetto? ";
                string listName;
                cin >> listName;

                auto currentListItr = shoppingLists.find(listName);
                if (currentListItr != shoppingLists.end()) {
                    string itemName;
                    cout << "Nome dell'oggetto da rimuovere: ";
                    cin >> itemName;

                    // Verifico se l'oggetto é presente nella lista
                    auto itemItr = currentListItr->second.getShoppingList().find(itemName);
                    if(itemItr != currentListItr->second.getShoppingList().end()) {
                        int quantityToRemove = 1;
                        cout << "Quanti ne vuoi rimuovere? (Inserisci un numero maggiore di 1 per rimuoverne di piú): ";
                        cin >> quantityToRemove;

                        // Rimuovi l'oggetto dalla lista trovata in shoppingLists
                        currentListItr->second.removeItem(itemName, quantityToRemove);
                    } else {
                        cout<<"L'oggetto specificato non esiste nella lista." << endl;
                    }
                } else {
                    cout << "La lista non esiste." << endl;
                }
                break;
            }
            case 4: {
                cout << "In quale lista vuoi impostare l'oggetto come acquistato? ";
                string listName;
                cin >> listName;

                auto currentListItr = shoppingLists.find(listName);
                if (currentListItr != shoppingLists.end()) {
                    string itemName;
                    cout << "Nome dell'oggetto da impostare come acquistato: ";
                    cin >> itemName;

                    // Imposta l'oggetto come acquistato nella lista trovata in shoppingLists
                    currentListItr->second.setBought(itemName);
                } else {
                    cout << "La lista non esiste." << endl;
                }
                break;
            }
            case 5: {
                cout<< "Inserisci il nome dell'utente ";
                string userName;
                cin>>userName;
                User newUser;
                users.insert(make_pair(userName, newUser));
                cout<<"Utente creato con successo."<<endl;

                cout<<"A quale lista vuoi unirti come osservatore? ";
                string listName;
                cin >> listName;

                auto userListItr = users.find(userName);
                if(userListItr != users.end()) {
                    auto currentListItr = shoppingLists.find(listName);
                    if (currentListItr != shoppingLists.end()) {
                        userListItr->second.addShoppingList(currentListItr->second);
                        cout << "Utente aggiunto come osservatore alla lista." << endl;
                    } else {
                        cout << "La lista specificata non esiste." << endl;
                    }
                }else{
                    cout<<"Scelta non valida. Riprova."<<endl;
                }
                break;
            }

            case 6: {
                cout << "Inserisci il nome dell'utente a cui vuoi aggiungere una lista: ";
                string userName;
                cin >> userName;

                // Verifica se l'utente esiste
                auto userListItr = users.find(userName);
                if(userListItr != users.end()){
                    cout<<"Inserisci il nome della lista da aggiungere: ";
                    string listName;
                    cin>>listName;

                    // Verifico se la lista esiste
                    auto listItr = shoppingLists.find(listName);
                    if(listItr != shoppingLists.end()){
                        //Aggiungi la lista esistente all'utente esistente
                        userListItr->second.addShoppingList(listItr->second);

                        cout<<"Lista aggiunta con successo all'utente"<<endl;
                    } else{
                        cout << "La lista specificata non esiste."<< endl;
                    }
                }else{
                    cout<< "L'utenet specificato non esiste."<< endl;
                }
                break;
            }
            case 7: {
                cout<<endl;
                cout << "Uscita dal programma. "<<endl;
                cout<<"Utenti: "<<endl;
                for(const auto &userPair : users){
                    const string &userName = userPair.first;
                    cout<<"Nome utente: "<< userName << endl;
                }

                cout<<endl;

                cout<<"Utenti e Liste a cui si sono aggiunti: "<< endl;
                for(const auto &userPair : users){
                    const string &userName = userPair.first;
                    const User &currentUser = userPair.second;

                    cout<<"Nome utente: "<<userName<<endl;
                    const map<string, shared_ptr<ShoppingList>> &userLists = currentUser.getMyLists();
                    if(!userLists.empty()) {
                        for (const auto &listPair : userLists) {
                            const string &listName = listPair.first;
                            cout << " - Lista: " << listName << endl;
                        }
                    } else{
                        cout<<"L'utente non é aggiunto a nessuna lista."<<endl;
                    }

                    cout<<endl;
                }

                cout<<"Contenuto delle liste:"<<endl;
                printAllLists(shoppingLists);
                return 0;
            }

            default: {
                cout << "Scelta non valida. Riprova." << endl;
            }
        }
    }
}

