//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_HPP
#define SLEKTSTRE_MYTREE_HPP

#include "string"
#include <chrono>
#include <ctime>
#include <ctime>   // localtime
#include <iomanip> // put_time
#include <iostream>//                    |   | |   |
#include <sstream> // stringstream
#include <string>
#include <utility>//                      |   |
#include <vector> //   Children ^            |



class node {
public:
    enum Gender {
        Male,
        Female,
        Empty
    };
    explicit node(std::string name, int age = 0, Gender gender = Empty) : name_(std::move(name)), age_(age),
                                                                          gender_(gender) {generation_++;};

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

    void setAge(int age) {
        age_ = age;
        birthYear_ = currentYear - age_;
    }
    [[nodiscard]] int getCurrentYear() const{
        return currentYear;
    }

    [[nodiscard]] int getAge() const {
        return getCurrentYear() - birthYear_;
    }


    void setGender(Gender &g) {
        gender_ = g;
    }

    void setName(std::string &name) {
        name_=name;
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
    [[nodiscard]] int getBirthYear()const{
        return birthYear_;
    }

    void printInfo() const {
        std::cout << name_ << "."
                              " Age: " << age_ << "."
                             " Gender: " << gender_;
    }

    void printChildren() const {

        for (int i = 0; i < children_.size(); i++) {
            std::cout << "Nr. " << i + 1 << ": ";
            children_[i].printInfo();
        }
    }

    [[nodiscard]] int getGender() const {
        if(gender_==Male){
            return Male;
        }
        else{
            return Female;
        }
    }    [[nodiscard]] std::string getGender_string() const {
        if(gender_==Male){
            return "Male";
        }
        else{
            return "Female";
        }
    }
 bool operator == (const node &a)const{

        if(a.ID_==ID_){
            return true;
        }
        else{
            return false;
        }
    }

private:
    std::string name_;
    std::vector<node> children_;
    node *parent_ = nullptr;
    int gender_ = Male;
    int age_ = 0;
    int currentYear = getCurrentYear();
    int birthYear_ = currentYear-age_;
    int generation_=0;
    int ID_=0;
};

int getcurrentYear() {
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

void select_parent(node &currentNode) {
    if (currentNode.isRoot()) {
        std::cout << "Current node have no parents. Returning to main menu. \n";

    } else {
        currentNode = *currentNode.getParent();
    }
}



#endif//SLEKTSTRE_MYTREE_HPP
