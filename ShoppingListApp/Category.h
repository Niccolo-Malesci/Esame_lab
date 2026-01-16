#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

class Category {
    std::string name;
public:
    Category(const std::string& n) : name(n) {}
    std::string getName() const { return name; }
};

#endif
