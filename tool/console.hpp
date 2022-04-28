//
// Created by Torstein on 22/04/2022.
//

#ifndef SLEKTSTRE_CONSOLE_HPP
#define SLEKTSTRE_CONSOLE_HPP

#include "myTree.hpp"

void changeInfo(node &currentNode);void select_person(node &currentNode);

void select_child(node &currentNode);

void main_menu(node &currentNode) {


    int selection;
    while (true) {
        std::cout << "\nCurrently selected is " << currentNode.getName() << "." << std::endl;
        std::cout << "1. Add child \n"
                     "2. Show children\n"
                     "3. Show parent\n"
                     "4. Show info on currently selected person\n"
                     "5. Edit selected person"
                     "6. Change person\n"
                     "0. Exit program";

        selection = inputToInt();

        switch (selection) {

            case 1: { // add child

                std::string name;
                std::getline(std::cin, name);

                break;
            }
            case 2: { // show children

                break;
            }

            case 3: { // show parent

                break;
            }
            case 4: { //show info on currently selected person

                break;
            }

            case 5: { //edit selected person

                break;
            }
            case 6: //change person

                break;
            case 0:
                std::cout << "Exiting program...";
                return;
            default:
                defaultMsg();
        }
    }
}

void changeInfo(node &currentNode) {
    int selection;

    std::cout << "\nCurrently selected is " << currentNode.getName() << "." << std::endl;
    std::cout << "1. Change age\n"
                 "2. Change name\n"
                 "3. Change gender\n"
                 "4. Back to main menu\n";
    selection = inputToInt();
    switch (selection) {
        case 1: {

            break;

        }
        case 2: {;
            break;
        }
        case 3:;
            break;

        case 4:
            main_menu(currentNode);
            break;
        default:
            defaultMsg();
            break;
    }

}

void select_person(node &currentNode) {
    int selection;
    while (true) {

        std::cout << "\n1. Select parent \n"
                     "2. Select child.\n"
                     "3. Go back to menu";
        selection = inputToInt();
        switch (selection) {

            case 1: {
                select_parent(currentNode);
                break;
            }
            case 2: {
                select_child(currentNode);
                break;
            }
            case 3:
                return;
            default:
                defaultMsg();
        }
        return;
    }
}

void select_child(node &currentNode) {
    int selection = 0;
    if (currentNode.isLeaf()) {
        std::cout << "Current node has no children. Returning to main menu. \n";

    } else {
        std::cout << "Choose one of the following numbers: \n";
        currentNode.printChildren();
        selection = inputToInt();
        currentNode = currentNode.getChildren()[selection - 1];
    }
}

#endif //SLEKTSTRE_CONSOLE_HPP
