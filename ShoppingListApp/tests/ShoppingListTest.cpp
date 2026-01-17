#include <gtest/gtest.h>
#include "ShoppingList.h"

TEST(ShoppingListTest, AddItemIncreasesCount) {
    ShoppingList list;
    list.addItem(ShoppingItem("Latte", 1, Category("Latticini")));

    EXPECT_EQ(list.getItemCount(), 1);
}

TEST(ShoppingListTest, RemoveItemDecreasesCount) {
    ShoppingList list;
    list.addItem(ShoppingItem("Pane", 1, Category("Forno")));
    list.removeLastItem();

    EXPECT_EQ(list.getItemCount(), 0);
}
