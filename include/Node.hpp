//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_NODE_HPP
#define SLEKTSTRE_NODE_HPP

#include "Person.hpp"
#include "functions.hpp"

//template<typename t>
class Node {
public:
    explicit Node(Person &member) : member_(&member){};

    [[nodiscard]] Person getMember() const {
        return *member_;
    }

    [[nodiscard]] Node getChild() const {
        return *child_;
    }

    [[nodiscard]] Node getParent(int i) const {
        if (i == 0) {
            return *parent_[0];
        } else {
            return *parent_[1];
        }
    }

    void addParent(Node &n) {
        n.child_ = this;
        if (n.member_->getGender() == n.member_->isFemale()) {
            *parent_[0] = n;
        }
        else {
            *parent_[1] = n;
        }
    }

    [[nodiscard]] bool isRoot() const {
        return child_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return parent_[0] && parent_[1] == nullptr;
    }

    void printPersonData() {
        std::cout << "name: " << member_->getName() << std::endl;
        std::cout << "age:  " << member_->getAge() <<", born "<< member_->getBirthYear()<< std::endl;
        std::cout << "gender:  " << member_->getGender_s() << std::endl;
        std::cout << "ID:   " << member_->getID() << std::endl;
    }

private:
    Person *member_ = nullptr;
    Node *child_ = nullptr;
    Node *parent_[2]{nullptr, nullptr};
    int ID_ = 0;
};


#endif//SLEKTSTRE_NODE_HPP
