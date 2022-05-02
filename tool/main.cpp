//
// Created by Torst on 14.03.2022.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "memory"
#include "console.hpp"
#include "Person.hpp"


int main() {
    std::cout << "Welcome to ancestor tree.\n\n";
    Person p = createPerson();
    Node root(p);
    mainMenu(root);

}