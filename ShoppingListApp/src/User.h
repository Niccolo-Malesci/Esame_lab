#ifndef USER_H
#define USER_H

#include "Observer.h"
#include "ShoppingList.h"

class User : public Observer {
    int lastKnownItemCount = 0;

public:
    void update(ShoppingList* list) override {
        lastKnownItemCount = list->getItemCount();
    }

    int getLastKnownItemCount() const {
        return lastKnownItemCount;
    }
};

#endif
