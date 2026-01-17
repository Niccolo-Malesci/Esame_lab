#include <gtest/gtest.h>
#include "ShoppingItem.h"

TEST(ShoppingItemTest, ItemCreationWorks) {
    Category c("Verdura");
    ShoppingItem item("Carote", 3, c);

    EXPECT_EQ(item.getName(), "Carote");
    EXPECT_EQ(item.getQuantity(), 3);
    EXPECT_EQ(item.getCategory().getName(), "Verdura");
}
