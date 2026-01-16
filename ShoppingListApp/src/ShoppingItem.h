#ifndef SHOPPING_ITEM_H
#define SHOPPING_ITEM_H

#include <string>
#include "Category.h"

class ShoppingItem {
    std::string name;
    int quantity;
    Category category;
public:
    ShoppingItem(const std::string& n, int q, const Category& c)
        : name(n), quantity(q), category(c) {}

    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    Category getCategory() const { return category; }
};

#endif
