#include <gtest/gtest.h>
#include "ShoppingList.h"

class TestObserver : public Observer {
public:
    bool notified = false;

    void update(ShoppingList*) override {
        notified = true;
    }
};

TEST(ObserverTest, ObserverIsNotifiedOnChange) {
    ShoppingList list;
    TestObserver observer;

    list.attach(&observer);
    list.addItem(ShoppingItem("Uova", 6, Category("Proteine")));

    EXPECT_TRUE(observer.notified);
}
