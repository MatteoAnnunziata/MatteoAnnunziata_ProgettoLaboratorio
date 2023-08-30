//
// Created by Matteo Annunziata on 25/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListTest : public ::testing::Test {
protected:
    void SetUp() override {
        sl.addItem(latte);
        sl.addItem(pane);
        sl.addItem(pasta);
        sl.addItem(cocomero);
    }

    ShoppingList sl{"spesa"};
    Item latte{"latte", "latte", 1};
    Item pane{"pane", "cibo", 3};
    Item pasta{"pasta", "cibo", 2};
    Item cocomero{"cocomero", "frutta", 5};
    User user;
};

TEST_F(ShoppingListTest, TestParametrizeConstructor) {
    ShoppingList s("grigliata");
    EXPECT_EQ(s.getShoppingListName(), "grigliata");
}

TEST_F(ShoppingListTest, AddItem) {
    Item carne("carne", "cibo", 4);
    sl.addItem(carne);
    int size = sl.getShoppingList().size();
    EXPECT_EQ(size, 5);     //numero di oggetti nella lista

    EXPECT_EQ(sl.notBought(), 15); //oggetti ancora da comprare

// controllo che un elemento aggiunto alla lista sia effettivamente presente e verifico che sia possibile modificarne la quantitá
    auto itr = sl.getShoppingList().find("cocomero");
    itr->second->setItemQuantity(1);
    auto s = itr->second->getItemQuantity();
    EXPECT_EQ(size, 5);
    EXPECT_EQ(s, 1);

}