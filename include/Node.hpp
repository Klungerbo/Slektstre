//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_NODE_HPP
#define SLEKTSTRE_NODE_HPP

#include "functions.hpp"
#include "Person.hpp"

template<typename t>
class Node {
public:

    explicit Node(t &member) : member_(&member) {};

    [[nodiscard]] Person getMember() const {
        return *member_;
    }

    [[nodiscard]] Person getParent() const {
        return *parent_;
    }

    [[nodiscard]] Person getChild(int i) const {
        if (i == 0) {
            return *children_[0];
        } else {
            return *children_[1];
        }
    }

    void addChild(t &p) {
        if (p.getGender() == p.isFemale()) {
            *children_[0] = p;
        } else {
            *children_[1] = p;
        }
    }

    void addParent(t &p) {
        *parent_ = p;
    }


    [[nodiscard]] bool isRoot() const {
        return parent_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return children_[0] && children_[1] == nullptr;
    }

private:
    Person *member_ = nullptr;
    Person *parent_ = nullptr;
    Person *children_[2]{nullptr, nullptr};
    int ID_ = 0;
};


#endif//SLEKTSTRE_NODE_HPP
