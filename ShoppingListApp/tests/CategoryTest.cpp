#include <gtest/gtest.h>
#include "Category.h"

TEST(CategoryTest, NameIsStoredCorrectly) {
    Category c("Frutta");
    EXPECT_EQ(c.getName(), "Frutta");
}