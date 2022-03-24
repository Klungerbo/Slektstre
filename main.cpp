//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"


int main(){
    int menu = 98;
    int exit = 99;

    std::cout<<"welcome to anchestor tree.\n\n"
               "please type the root name: ";
    std::string name;
    std::cin >> name;
    node root(name);

    std::cout<<"your root name is "<<name<<std::endl;
    node currentNode = root;

    int c = 1;
    bool exitLoop = false;
    while(!exitLoop) {
        switch (c) {

            case 1: {
                std::cout <<"parent is " << currentNode.getName()<< std::endl;
                std::cout << "type name of child: ";
                std::cin >> name;
                std::string name2 = name;
                node name(name2);
                currentNode.addChild(name);
                c = menu;
                break;
            }
            case 2: {

                for (int i = 0; i < currentNode.getAmountOfChildren(); i++) {
                    auto a = currentNode.getChildren();
                    std::cout << "child nr. " << i+1 << " is " << a[i].getName() << std::endl;
                }
                c = menu;

                break;
            }
            case 3: {
                auto a = currentNode.getParent();
                if(a->getParent()!= nullptr){
                    std::cout << "parent is " << a->getName() << std::endl;
                }
                else {
                    std::cout<<"try again"<<std::endl;
                }
                c = menu;
                break;
            }
            case 4:
                std::cout<< "who is the  parent?";
                for (int i = 0; i < currentNode.getAmountOfChildren(); i++) {
                    auto a = currentNode.getChildren();
                    std::cout << "child nr. " << i+1 << " is " << a[i].getName() << std::endl;
                }
                int parent;
                std::cin>>parent;
                currentNode = currentNode.getChildren()[parent];
                c=1;



            case 98: { //menu
                std::cout << "1. add sibling\n"
                             "2. get siblings\n"
                             "3. get parent\n"
                             "4. add child\n"
                             "5. exit program\n";
                std::cin >> c;
                switch (c) {
                    case 1:
                        c=c;
                        break;
                    case 2:
                        c=c;
                        break;
                    case 3:
                        c=c;
                        break;
                    case 4:
                        c=c;
                        break;
                    case 5:
                        c = exit;
                        break;
                    default:
                        std::cout << "invalid number. try again: ";
                        std::cin >> c;
                }
                break;
            }

            case 99: { //exit case
                exitLoop = true;
                std::cout << "exiting program...";
                break;
            }
            default: {

                std::cout << "invalid number. try again: ";
                std::cin >> c;
            }
       }
    }
       return 1;
}