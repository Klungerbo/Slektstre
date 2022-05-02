//
// Created by Torstein on 22/04/2022.
//

#ifndef SLEKTSTRE_CONSOLE_HPP
#define SLEKTSTRE_CONSOLE_HPP
#include "Node.hpp"
#include "Person.hpp"
Person createPerson(){

    std::string name;
    Person::Gender gender = Person::Empty;
    int age;
    int input;

    std::cout<<"enter name: "<<std::endl;
    name = enterName();
    std::cout<<"enter age: "<<std::endl;
    age= enterAge();
    std::cout<<"Press 1. for male,\n"
                 "Press 2. for female "<<std::endl;
    std::cin>>input;
    switch (input) {
        case 1:
            gender = Person::Male;
            break;
        case 2:
            gender = Person::Female;
            break;
        default:
            defaultMsg();
            std::cin>>input;

    }
    Person p(name,age,gender);
    return p;
}
void changeSelection(){
    auto input=0;
    std::cout<<"1. mother\n"
                 "2. father\n"
                 "3. child.";
    input = inputDigit();
    switch (input) {
        case 1:

            break;
        case 2:
            break;
        default:
            defaultMsg();
            changeSelection();

    }
}

void mainMenu(Node currentNode){
    std::cout<<"currently selected node is: "<<currentNode.getMember().getName()<<std::endl;
    int input=0;
    std::cout<<"1. add new parent: \n"
                 "2. get info on current person\n"
                 "3. change selected person\n";
    std::cin>>input;
    std::cout<<std::endl;
    switch (input) {
        case 1: {
            Person p = createPerson();
            Node n(p);
            currentNode.addParent(n);
            break;
        }

        case 2:{
            currentNode.printPersonData();
            break;
        }

        case 3:{


            break;
        }
        default:
            defaultMsg();
            mainMenu(currentNode);


    }
}


#endif //SLEKTSTRE_CONSOLE_HPP
