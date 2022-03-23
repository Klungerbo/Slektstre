//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"


int main(){

    std::cout<<"welcome to anchestor tree.\n please type the root name: ";
    std::string name;
    std::cin >> name;
    node root(name);

    std::cout<<"your root name is "<<name<<std::endl;
    std::cout<<"add child: \n";

    int c = 1;
    bool exitLoop = false;
    while(!exitLoop) {
        switch (c) {

            case 1: {
                std::cin >> name;
                if (root.getAmountOfChildren() == 1) {
                    node two(name);
                    root.addChild(two);
                    std::cout << "name of child two is: " << name;

                }
                if (!root.getAmountOfChildren()) {
                    node one(name);
                    root.addChild(one);
                    std::cout << "name of child one is " << name << std::endl;

                }
                std::cout << "do you wish to add another child? \n"
                             "1. Yes\n"
                             "2. No\n";
                std::cin >> c;
                if (c==2){c=99;}
                break;
            }
            case 2:
                break;
            case 99:
                exitLoop=true;
                std::cout<<"exiting program...";
                break;

            default:
                std::cout << "invalid number. try again: ";
                std::cin >> c;

       }
    }
       return 1;
}