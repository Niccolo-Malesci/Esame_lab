#include <iostream>
#include "Category.h"
#include "ShoppingItem.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
    Category frutta("Frutta");
    Category latticini("Latticini");
    Category proteine("Proteine");

    ShoppingList listaSpesa1;
    ShoppingList listaSpesa2;

    User nicco;
    User virginia;

    nicco.addList(&listaSpesa1);
    virginia.addList(&listaSpesa1);
    virginia.addList(&listaSpesa2);

    listaSpesa1.addItem(ShoppingItem("Mele", 5, frutta));
    listaSpesa1.addItem(ShoppingItem("Latte", 2, latticini));
    listaSpesa2.addItem(ShoppingItem("Uova", 12, proteine));

    std::cout << "Nicco conosce la lista 1:" << std::endl;
    for (const auto& item : nicco.getLastKnownItems()) {
        std::cout << "- " << item.getName() 
                  << " (" << item.getQuantity() << ")"
                  << " Categoria: " << item.getCategory().getName()
                  << std::endl;
    }

    std::cout << "\nVirginia conosce la lista 1:" << std::endl;
    for (const auto& item : virginia.getLists()[0]->getItems()) {
        std::cout << "- " << item.getName() 
                  << " (" << item.getQuantity() << ")"
                  << " Categoria: " << item.getCategory().getName()
                  << std::endl;
    }

    std::cout << "\nVirginia conosce la lista 2:" << std::endl;
    for (const auto& item : virginia.getLastKnownItems()) {
        std::cout << "- " << item.getName() 
                  << " (" << item.getQuantity() << ")"
                  << " Categoria: " << item.getCategory().getName()
                  << std::endl;
    }

    listaSpesa1.removeLastItem();

    std::cout << "\nDopo rimozione ultimo elemento dalla lista 1:" << std::endl;
    std::cout << "Nicco conosce la lista 1:" << std::endl;
    for (const auto& item : nicco.getLastKnownItems()) {
        std::cout << "- " << item.getName() 
                  << " (" << item.getQuantity() << ")"
                  << " Categoria: " << item.getCategory().getName()
                  << std::endl;
    }

    return 0;
}   