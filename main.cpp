//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"



int main() {
    int menu = 98;
    int exit = 99;
    int c = menu;


    std::cout << "Welcome to ancestor tree.\n\n"
                 "Type the root name: ";
    std::string name;
    std::getline(std::cin, name);
    node root(name);

    std::cout << "The root name is " << name << "." << std::endl;
    node currentNode = root;


    bool exitLoop = false;
    while (!exitLoop) {

        switch (c) {

            case 1: { // change selected person
                std::cout << "1. Select parent \n"
                             "2. Select child.\n"
                             "3. Go back to menu";
                std::cin>>c;
                switch (c) {

                    case 1: {
                        if (currentNode.isRoot()) {
                            std::cout << "Current node have no parents. select something else. \n";
                            std::cin>>c;
                        }
                        else {
                            currentNode = *currentNode.getParent();
                        }
                        break;
                    }
                    case 2: {
                        if (currentNode.isLeaf()) {
                            std::cout << "Current node has no children. select something else. \n";
                            std::cin>>c;
                        }
                        else {
                            std::cout << "Choose one of the following numbers: \n";
                            currentNode.printChildren();
                            std::cin>>c;
                            currentNode = currentNode.getChildren()[c+1];
                        }
                        break;
                    }
                    case 3:
                        c = menu;
                        break;
                    default:
                        defaultMsg();
                        std::cin>>c;
                }

            }
            case 2: {
                if(currentNode.isLeaf()){
                    std::cout << "Current node have no children. select something else. \n";

                }
                else{
                    currentNode.printChildren();
                }
                c = menu;

                break;
            }
            case 3: {
                if(currentNode.isRoot()){
                    std::cout << "Current node have no parents. select something else. \n";
                }
                else{
                    std::cout<<currentNode.getParent()->getName();
                }
                c = menu;
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
                std::cin>>c;


                switch (c) {
                    case 1:
                        c = c;
                        break;
                    case 2:
                        c = c;
                        break;
                    case 3:
                        c = c;
                        break;
                    case 4:
                        c = c;
                        break;
                    case 5:
                        c = exit;
                        break;
                    default:
                        defaultMsg();
                        std::cin>>c;
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
                std::cin>>c;
                break;
            }
        }

    }
    return 1;
}