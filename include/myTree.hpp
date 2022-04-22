//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_HPP
#define SLEKTSTRE_MYTREE_HPP

#include <iostream>                      //                    |   | |   |
#include <utility>                        //                      |   |
#include <vector>                        //   Children ^            |
#include "string"


class node {
public:
    explicit node(std::string name, int age = 0, std::string gender = "") : name_(std::move(name)), age_(age),
                                                                            gender_(std::move(gender)) {};

    void addChild(node &n) {
        n.parent_ = this;
        children_.emplace_back(n);
    }

    [[nodiscard]] auto getParent() const {
        return parent_;
    }

    [[nodiscard]] auto getChildren() const {
        return children_;
    }

    void setAge() {
        int age;
        std::cout << "current age is: " << age_ << "\n";
        std::cout << "Enter new age: ";
        std::cin >> age;
        age_ = age;
    }

    void setGender() {
        std::string gender;
        std::cout << "current gender is: " << gender_ << "\n";
        std::cout << "Enter new gender: ";

        std::cin >> gender;
        gender_ = gender;
    }

    void setName() {
        std::string name;
        std::cout << "current name is: " << name_ << "\n";
        std::cout << "Enter new name: ";
        std::getline(std::cin, name_);
    }

    [[nodiscard]] bool isRoot() const {
        return parent_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return children_.empty();
    }

    std::string getName() const {
        return name_;
    }

    void printInfo()  const{
        std::cout << name_ << ". Age: " << age_ << ". Gender: " << gender_;
    }

    void printChildren() const {

        for (int i = 0; i < children_.size(); i++) {
            std::cout << "Nr. " << i + 1 << ": ";
            children_[i].printInfo();
        }
    }

    std::string getGender() const {
        return gender_;
    }

    int getAge() const {
        return age_;
    }


private:
    std::string name_;
    std::vector<node> children_;
    node *parent_ = nullptr;
    std::string gender_;
    int age_ = 0;
};

void main_menu(node &currentNode);

int inputToInt() {
    std::string s;
    std::getline(std::cin, s);
    return stoi(s);
}

void defaultMsg() {
    std::cout << "Invalid number. Try again: ";
}

void get_children(const node &currentNode) {
    if (currentNode.isLeaf()) {
        std::cout << "Current node have no children. Select something else. \n";
    } else {
        currentNode.printChildren();
    }
}

void select_parent(node &currentNode) {
    if (currentNode.isRoot()) {
        std::cout << "Current node have no parents. Returning to main menu. \n";

    } else {
        currentNode = *currentNode.getParent();
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

void get_parent(node &currentNode) {
    if (currentNode.isRoot()) {
        std::cout << "Current node have no parents. select something else. \n";
    } else {
        std::cout << currentNode.getParent()->getName();
    }
}

void add_child(node &currentNode) {
    std::string name;
    std::cout << "Type child name: " << std::endl;
    std::getline(std::cin, name);
    node n(name);
    currentNode.addChild(n);
}

void search(node &sNode, std::string &name) {
    node previous("a");
    previous = sNode;

    while (sNode.getName() != name) {
        for (auto a: sNode.getChildren()) {
            if (a.getName() == name) {
                sNode = a;
                break;
            } else if (!a.isLeaf()) {
                search(a, name);
            }
        }
    }
    if (sNode.getName() == name) {
        int selection = 0;
        std::cout << name << " is found, select person? \n1.Yes     2.No\n";
        selection = inputToInt();
        switch (selection) {
            case1:
                break;
            case2:
                sNode = previous;
                break;
        }
    }
}

node search_person(node &currentNode) {
    node sNode("s");
    sNode = currentNode;
    while (!sNode.isRoot()) {
        sNode = *currentNode.getParent();
    }
    std::cout << "Enter person name: ";
    std::string name;
    std::getline(std::cin, name);
    search(sNode, name);
    main_menu(sNode);
    return {sNode};
}


void info_menu(node &currentNode) {
    std::cout << "name: " << currentNode.getName() << "\n";
    std::cout << "age: " << currentNode.getAge() << "\n";
    std::cout << "gender: " << currentNode.getGender() << "\n";
    std::cout << "children: ";
    std::cout << "Parent: " << currentNode.getParent();
    currentNode.printChildren();
}

void change_info(node &currentNode) {
    int selection;

    std::cout << "\nCurrently selected is " << currentNode.getName() << "." << std::endl;
    std::cout << "1. Change age\n"
                 "2. Change name\n"
                 "3. Change gender\n"
                 "4. Back to main menu\n";
    selection = inputToInt();
    switch (selection) {
        case 1: {
            currentNode.setAge();
            break;

        }
        case 2: {
            currentNode.setName();
            break;
        }
        case 3:
            currentNode.setGender();
            break;

        case 4:
            main_menu(currentNode);
            break;
        default:
            defaultMsg();
            break;
    }

}

void main_menu(node &currentNode) {
    int selection;
    while (true) {
        std::cout << "\nCurrently selected is " << currentNode.getName() << "." << std::endl;
        std::cout << "1. Change selected person\n"
                     "2. Get info on currently selected\n"
                     "3. Add child\n"
                     "4. Search for person\n"
                     "5. Exit program\n"
                     "6. Show all people\n"
                     "7. Change info on currently selected";
        selection = inputToInt();

        switch (selection) {

            case 1: { // change selected person
                select_person(currentNode);
                break;
            }
            case 2: {
                break;
            }

            case 3: { // addChild
                add_child(currentNode);
                break;
            }
            case 4: {
                search_person(currentNode);
                break;
            }

            case 5:
                std::cout << "Exiting program...";
                return;
            case 6: {
                main_menu(currentNode);//placeholder
                break;
            }
            case 7:
                change_info(currentNode);
                break;
            default:
                defaultMsg();
        }
    }
}


#endif //SLEKTSTRE_MYTREE_HPP
