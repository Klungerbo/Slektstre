//
// Created by Torstein on 22/04/2022.
//

#ifndef SLEKTSTRE_CONSOLE_HPP
#define SLEKTSTRE_CONSOLE_HPP
#include "Node.hpp"
#include "Person.hpp"

Person createPerson() {
    std::string name;
    Person::Gender gender = Person::Empty;
    int age;
    int input;

    std::cout << "enter name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "enter age: " << std::endl;
    std::cin >> age;

    std::cout << "Press 1. for male,\n"
                 "Press 2. for female "
              << std::endl;
    std::cin >> input;
    switch (input) {
    case 1:
        gender = Person::Male;
        break;
    case 2:
        gender = Person::Female;
        break;
    default:
        defaultMsg();
        std::cin >> input;
    }
            Person p(name, age, gender);
            return p;

}
void changeSelection(Node &currentNode){
    int input;
    std::cout<<"1. mother\n"
                 "2. father\n"
                 "3. child.\n"
                 "4. return";
    input = inputDigit();
    switch (input) {
        case 1:
            currentNode = currentNode.getMother();
            break;
        case 2:
            currentNode = currentNode.getFather();
            break;
        case 3:
            currentNode = currentNode.getChild();
        case 4:
            break;
        default:
            defaultMsg();
            changeSelection(currentNode);

    }
}

void mainMenu(Node &currentNode){
    std::cout<<"currently selected node is: "<<currentNode.getPerson().getName()<<std::endl;
    std::cout<<"1. add new parent: \n"
                 "2. get info on current person\n"
                 "3. change selected person\n"
                 "0. exit";
    int input;
    std::cin>>input;
    std::cin.ignore(1000, '\n');
    std::cout<<std::endl;
    bool exit = false;
    while(!exit){


        switch (input) {
            case 1: {
                Person p = createPerson();
                if(p.isMale()){
                    currentNode.addFather(p);
                }
                else{
                    currentNode.addMother(p);
                }
                break;
            }

            case 2:{
                currentNode.printPersonData();
                break;
            }

            case 3:{


                break;
            }
            case 0:
                exit = true;
                break;
            default:
                defaultMsg();
                mainMenu(currentNode);



        }
    }

}


#endif //SLEKTSTRE_CONSOLE_HPP
