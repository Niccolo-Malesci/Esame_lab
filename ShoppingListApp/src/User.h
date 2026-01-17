#ifndef USER_H
#define USER_H

#include "Observer.h"
#include "ShoppingList.h"
#include <vector>

class User : public Observer {
    std::vector<ShoppingList*> myLists;           
    std::vector<ShoppingItem> lastKnownItems;     

public:
    void addList(ShoppingList* list) {
        myLists.push_back(list);
        list->attach(this);
        update(list); 
    }

    void removeList(ShoppingList* list) {
        myLists.erase(std::remove(myLists.begin(), myLists.end(), list), myLists.end());
        list->detach(this);
    }

    void update(ShoppingList* list) override {
        lastKnownItems = list->getItems();
    }

    size_t getLastKnownItemCount() const {
        return lastKnownItems.size();
    }

    const std::vector<ShoppingItem>& getLastKnownItems() const {
        return lastKnownItems;
    }

    const std::vector<ShoppingList*>& getLists() const {
        return myLists;
    }
};

#endif
