//
// Created by Torstein on 22/04/2022.
//

#ifndef SLEKTSTRE_CONSOLE_HPP
#define SLEKTSTRE_CONSOLE_HPP
#include "Node.hpp"
#include "Person.hpp"
void mainMenu(Node &currentNode);

Person createPerson() {
    std::string name;
    Person::Gender gender = Person::Empty;
    int age;
    int input;

    std::cout << "enter name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "enter age: " << std::endl;
    std::cin >> age;
    std::cin.ignore(10000, '\n');
    std::cin.clear();


    while (gender == Person::Empty) {
        std::cout << "Press 1. for male,\n"
                     "Press 2. for female "
                  << std::endl;
        std::cin >> input;
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        switch (input) {
            case 1:
                gender = Person::Male;
                break;
            case 2:
                gender = Person::Female;
                break;
            default:
                defaultMsg();
                break;
        }
    }
    Person p(name, age, gender);
    return p;
}
void showRelations(Node &currentNode){
    if (currentNode.getFather() != nullptr) {
        Person father = currentNode.getFather()->getPerson();
        std::cout << "Father: " << father.getName() << std::endl;

    }
    if (currentNode.getMother() != nullptr) {
        Person mother = currentNode.getMother()->getPerson();
        std::cout << "Mother: " << mother.getName() << std::endl;

    }
    if (!currentNode.isRoot()) {
        Person child = currentNode.getChild().getPerson();
        std::cout << "Child: " << child.getName() << std::endl;


    } else if (currentNode.isRoot() && currentNode.isLeaf()) {
        std::cout << currentNode.getPerson().getName() << " has no relations\n"
                  << std::endl;
    }
}
void changeCurrentNode(Node &n) {
    std::cout << "1. select mother\n";
    std::cout << "2. select father\n";
    std::cout << "3. select child\n";
    int input;
    std::cin>>input;
    switch (input) {
        case 1:
            if (n.getMother()!= nullptr){
                Node nextCurrentNode(n.getMother()->getPerson());
                mainMenu(nextCurrentNode);
            }
            else{
                std::cout<<"person have no mother\n";
            }
            break;

        case 2:
            if (n.getFather()!= nullptr){
                Node nextCurrentNode(n.getFather()->getPerson());
                mainMenu(nextCurrentNode);
            }
            else{
                std::cout<<"person have no father\n";
            }

            break;
        case 3:
            if (n.isRoot()){
                std::cout<<"person have no child\n";

            }
            else{
                Node nextCurrentNode(n.getChild().getPerson());
                n=nextCurrentNode;
            }
            break;


    }
}

void mainMenu(Node &currentNode) {
    bool exit = false;
    while (!exit) {
        std::cout << "main menu" << std::endl;
        std::cout << "1. add a new parent to " << currentNode.getPerson().getName() << "\n"
                                                                                       "2. get info on "
                  << currentNode.getPerson().getName() << "\n"
                                                          "3. show relations\n"
                                                          "4.Change currently selected\n"
                                                          "0. exit\n"
                                                          "select: ";
        int input;
        std::cin >> input;
        std::cin.ignore(1000, '\n');
        std::cout << std::endl;

        switch (input) {
            case 1: {
                Person p = createPerson();
                if (p.isMale()) {
                    currentNode.addFather(p);
                }
                else{
                    currentNode.addMother(p);
                }
                break;
            }

            case 2: {
                currentNode.printPersonData();
                break;
            }

            case 3: {
                showRelations(currentNode);

                break;
            }
            case 4:
                changeCurrentNode(currentNode);
                break;
            case 0:
                exit = true;
                break;
            default:
                defaultMsg();
                mainMenu(currentNode);
        }
    }
}



#endif//SLEKTSTRE_CONSOLE_HPP
