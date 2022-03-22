//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "myTree.h"


int main(){
    int c;
    std::cout<<"welcome to anchestor tree. \n please type the root name: ";
    std::string name;
    std::cin >> name;
    node root(name);

    std::cout<<"your root name is "<<name<<std::endl;
    std::cout<<"1. add child \n"
               "2. traverse upwards \n"
               "3. traverse downwards";
    std::cin>>c;
    switch (c) {
        case 1:
            std::cout<<"type child name: ";
            std::cin>>name;
            node name(name);

            break;
        case2:
            break;


    }
   node ancestor("ancestor");
   node b("bcestor");
   ancestor.addChild(b);
   std::cout<<b.getParent()->getName();


       return 1;
}