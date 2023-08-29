//
// Created by Matteo Annunziata on 24/08/2023.
//

#include "gtest/gtest.h"
#include "../Item.h"

//testo il costruttore e il metodo getter, creo un oggetto Item con valori specifici e tramite e asserzioni di Google Test verifico che i valori restituiti dal gettere corrispondano ai valori che ho impostato
TEST(ItemTest, ConstructorAndAccessors
){
Item item("Mela", "Frutta", 5);

EXPECT_EQ(item
.

getItemName(),

"Mela");
EXPECT_EQ(item
.

getCategory(),

"Frutta");
EXPECT_EQ(item
.

getItemQuantity(),

5);
EXPECT_FALSE(item
.

isBought()

);
}

// adesso testo il metodo setter della classe Item
TEST(ItemTest, Setters
){
Item item("Arancia", "Frutta");

item.setItemQuantity(3);
EXPECT_EQ(item
.

getItemQuantity(),

3);

item.setItemBought(true);
EXPECT_TRUE(item
.

isBought()

);
}

//questa classe di test serve per verificare se il costruttore di Item lancia un eccezione quando si tenta di creare un oggetto con una quantitá negativa
TEST(ItemTest, QuantityException
){
EXPECT_THROW(Item("Banana", "Frutta", -1), std::out_of_range
);
}