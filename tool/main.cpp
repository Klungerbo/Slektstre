//
// Created by Torst on 14.03.2022.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "memory"
#include "console.hpp"


int main() {
    std::unique_ptr<int> population = std::make_unique<int>();

    std::cout << "Welcome to ancestor tree.\n\n"
                 "Type the root name: ";
    std::string name;
    std::getline(std::cin, name);
    node root(name);

    std::cout << "The root name is " << name << "." << std::endl;
    node currentNode = root;

    main_menu(currentNode);

    return 0;
}