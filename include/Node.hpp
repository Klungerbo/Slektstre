//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_NODE_HPP
#define SLEKTSTRE_NODE_HPP

#include <utility>

#include "Person.hpp"
#include "functions.hpp"

//template<typename t>
class Node {
public:
    explicit Node(Person person) : person_(std::move(person)){};

    [[nodiscard]] Person getPerson() const {
        return person_;
    }

    [[nodiscard]] Node getChild() const {
        return std::move(*child_);
    }

    Node getFather() {
        return std::move(*father);

    }

    Node getMother() {
        return std::move(*mother) ;
    }

    void addMother(Person p) {
        auto n = std::make_unique<Node>(p);
        n->child_=this;

        if (!mother){
            mother=std::move(n);
        }
        else{
            std::cout<<"node already have this parent";
        }
    }

    void addFather( Person &p) {
        auto n = std::make_unique<Node>(p);
        n->child_=this;

        if(!father){
            father = std::move(n);

        }
        else{
            std::cout<<"node already have this parent";
        }
    }

    [[nodiscard]] bool isRoot() const {
        return child_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return !mother && !father;
    }

    void printPersonData() {
        std::cout << "name: " << person_.getName() << std::endl;
        std::cout << "age:  " << person_.getAge() << ", born " << person_.getBirthYear() << std::endl;
        std::cout << "gender:  " << person_.getGender_s() << std::endl;
        std::cout << "ID:   " << person_.getID() << std::endl;
    }

private:
    Person person_;
    Node *child_= nullptr;
    std::unique_ptr<Node> mother = nullptr;
    std::unique_ptr<Node> father = nullptr;
};


#endif//SLEKTSTRE_NODE_HPP
