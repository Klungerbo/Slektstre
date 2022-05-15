//
// Created by Torst on 14.03.2022.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "console.hpp"
#include "Person.hpp"


int main() {

        std::cout << "Welcome to ancestor tree.\n\n";
        Person p = createPerson();
        std::unique_ptr<Node> root = std::make_unique<Node>(Node(p));
        mainMenu(*root);

return 0;
}