//
// Created by Matteo Annunziata on 24/08/2023.
//

#include "gtest/gtest.h"
#include "../User.h"

//testo i metodi addShoppingList e removeShoppingList della classe user, creo un oggetto User e due oggetti ShoppingList, utilizzo quindi le asserzioni EXPECT_EQ per verificare se le operazioni sono state eseguite
TEST(UserTest, AddAndRemoveShoppingList) {
    User user;
    ShoppingList list1("List1");
    ShoppingList list2("List2");

    user.addShoppingList(list1);
    user.addShoppingList(list2);

    const map<string, shared_ptr<ShoppingList>> &lists = user.getMyLists();
    EXPECT_EQ(lists.size(), 2);

    user.removeShoppingList("List1");
    EXPECT_EQ(lists.size(), 1);
}

