//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_HPP
#define SLEKTSTRE_MYTREE_HPP

#include <iostream>                      //                    |   | |   |
#include <utility>                        //                      |   |
#include <vector>                        //   Children ^            |
#include "string"
#include <chrono>
#include <ctime>
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>
int getCurrentYear();


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
        yearOfBirth_ = currentYear-age_;
    }
    int getAge() const{
        return getCurrentYear()-yearOfBirth_;
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

    [[nodiscard]] std::string getName() const {
        return name_;
    }

    void printInfo() const {
        std::cout << name_ << ". Age: " << age_ << ". Gender: " << gender_;
    }

    void printChildren() const {

        for (int i = 0; i < children_.size(); i++) {
            std::cout << "Nr. " << i + 1 << ": ";
            children_[i].printInfo();
        }
    }

    [[nodiscard]] std::string getGender() const {
        return gender_;
    }




private:
    std::string name_;
    std::vector<node> children_;
    node *parent_ = nullptr;
    std::string gender_;
    int age_ = 0;
    int currentYear = 2022;
    int birthYear_=currentYear-age_;
    int yearOfBirth_ = 0;
};

int getcurrentYear(){
    return 2022;
}
/*int getCurrentYear() {
    auto currentDateTime= std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(currentDateTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    auto currentDateTime_s = ss.str();
    std::string currentYear_s;
    for(int i = 1; i>5; i++){
        currentYear_s+=(currentDateTime_s[i]);
    }
    int currentYear = stoi(currentYear_s);
    std::cout <<currentYear;
    return currentYear;
}*/

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


#endif //SLEKTSTRE_MYTREE_HPP
