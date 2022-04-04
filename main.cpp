//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"




int main() {
    int menu = 98;
    int exit = 99;
    int menuPointer = menu;


    std::cout << "Welcome to ancestor tree.\n\n"
                 "Type the root name: ";
    std::string name;
    std::getline(std::cin, name);
    node root(name);

    std::cout << "The root name is " << name << "." << std::endl;
    node currentNode = root;


    bool exitLoop = false;
    while (!exitLoop) {

        switch (menuPointer) {

            case 1: { // change selected person
                std::cout << "1. Select parent \n"
                             "2. Select child.\n"
                             "3. Go back to menu";
                menuPointer = menuInput();
                switch (menuPointer) {

                    case 1: {
                        if (currentNode.isRoot()) {
                            std::cout << "Current node have no parents. select something else. \n";
                            menuPointer = menuInput();
                            currentNode = *currentNode.getParent();
                        }
                        else {
                            currentNode = *currentNode.getParent();
                        }
                        break;
                    }
                    case 2: {
                        if (currentNode.isLeaf()) {
                            std::cout << "Current node has no children. select something else. \n";
                            menuPointer = menuInput();
                        }
                        else {
                            std::cout << "Choose one of the following numbers: \n";
                            currentNode.printChildren();
                            menuPointer = menuInput();
                            currentNode = currentNode.getChildren()[menuPointer-1];
                        }
                        break;
                    }
                    case 3:
                        menuPointer = menu;
                        break;
                    default:
                        defaultMsg();
                        menuPointer = menuInput();
                }

            }
            case 2: { // print children
                if(currentNode.isLeaf()){
                    std::cout << "Current node have no children. select something else. \n";

                }
                else{
                    currentNode.printChildren();
                }
                menuPointer = menu;

                break;
            }
            case 3: { // print parent
                if(currentNode.isRoot()){
                    std::cout << "Current node have no parents. select something else. \n";
                }
                else{
                    node previousNode("p");
                    previousNode = *currentNode.getParent();
                    std::cout<<previousNode.getName()<<std::endl;
                }
                menuPointer = menu;
                break;
            }
            case 4: { //addChild
                std::cout << "Type child name: " << std::endl;
                std::getline(std::cin, name);
                node n(name);
                currentNode.addChild(n);
            }


            case 98: { //menu
                std::cout << "Currently selected is " << currentNode.getName() << "." << std::endl;
                std::cout << "1. Change selected person\n"
                             "2. Get children\n"
                             "3. Get parent\n"
                             "4. Add child\n"
                             "5. Exit program\n";
                std::string s;
                menuPointer = menuInput();


                switch (menuPointer) {
                    case 1:
                        menuPointer  = menuPointer;
                        break;
                    case 2:
                        menuPointer = menuPointer;
                        break;
                    case 3:
                        menuPointer = menuPointer;
                        break;
                    case 4:
                        menuPointer = menuPointer;
                        break;
                    case 5:
                        menuPointer = exit;
                        break;
                    default:
                        defaultMsg();
                        menuPointer = menuInput();
                }
                break;
            }

            case 99: { //exit case
                exitLoop = true;
                std::cout << "Exiting program...";
                break;
            }
            default: {

                defaultMsg();
                menuPointer = menuInput();
                break;
            }
        }

    }
    return 1;
}