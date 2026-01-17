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
        notifyObservers();
    }

    void removeLastItem() {
        if (!items.empty()) {
            items.pop_back();
            notifyObservers();
        }
    }

    size_t getItemCount() const {
        return items.size();
    }

    const std::vector<ShoppingItem>& getItems() const {
        return items;
    }

    void attach(Observer* o) override {
        observers.push_back(o);
    }

    void detach(Observer* o) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), o),
            observers.end()
        );
    }

    void notifyObservers() override {
        for (Observer* o : observers) {
            o->update(this);
        }
    }
};

#endif
