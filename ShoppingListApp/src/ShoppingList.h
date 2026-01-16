#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <vector>
#include <algorithm>
#include "Subject.h"
#include "ShoppingItem.h"

class ShoppingList : public Subject {
    std::vector<ShoppingItem> items;
    std::vector<Observer*> observers;

public:
    void addItem(const ShoppingItem& item) {
        items.push_back(item);
    }

    void removeLastItem() {
        if (!items.empty()) {
            items.pop_back();
        }
    }

    int getItemCount() const {
        return items.size();
    }

    void attach(Observer* o) override {}
    void detach(Observer* o) override {}
    void notifyObservers() override {}
};

#endif
