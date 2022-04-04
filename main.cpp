//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"
#include <string>



int main()
{
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