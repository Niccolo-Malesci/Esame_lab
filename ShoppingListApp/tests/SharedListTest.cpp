#include <gtest/gtest.h>
#include "ShoppingList.h"
#include "User.h"

TEST(SharedListTest, MultipleUsersReceiveUpdates) {
    ShoppingList list;

    User user1;
    User user2;

    user1.addList(&list);
    user2.addList(&list);

    ShoppingItem item("Latte", 2, Category("Latticini"));
    list.addItem(item);

    EXPECT_EQ(user1.getLastKnownItemCount(), 1);
    EXPECT_EQ(user2.getLastKnownItemCount(), 1);

    EXPECT_EQ(user1.getLastKnownItems()[0].getName(), "Latte");
    EXPECT_EQ(user2.getLastKnownItems()[0].getName(), "Latte");

    ShoppingItem item2("Pane", 1, Category("Forno"));
    list.addItem(item2);

    EXPECT_EQ(user1.getLastKnownItemCount(), 2);
    EXPECT_EQ(user2.getLastKnownItemCount(), 2);

    list.removeLastItem();

    EXPECT_EQ(user1.getLastKnownItemCount(), 1);
    EXPECT_EQ(user2.getLastKnownItemCount(), 1);

    
    EXPECT_EQ(user1.getLastKnownItems()[0].getName(), "Latte");
    EXPECT_EQ(user2.getLastKnownItems()[0].getName(), "Latte");
}
