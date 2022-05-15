//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_NODE_HPP
#define SLEKTSTRE_NODE_HPP

#include <memory>
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

    Node getChild() const {
        return *child_;
    }

    std::shared_ptr<Node> getFather() {
        return father_;

    }

    std::shared_ptr<Node> getMother() {
        return mother_;
    }

    void addMother(Person &p) {
        auto n = std::make_shared<Node>(p);
        n->child_ = this;

        if (!mother_){
            mother_=std::move(n);
        }
        else{
            std::cout<<"node already have this parent";
        }
    }

    void addFather( Person &p) {
        auto n = std::make_shared<Node>(p);
        n->child_=this;

        if(!father_){
            father_ = std::move(n);

        }
        else{
            std::cout<<"node already have this parent";
        }
    }

    [[nodiscard]] bool isRoot() const {
        return child_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return !mother_ && !father_;
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
    std::shared_ptr<Node> mother_ = nullptr;
    std::shared_ptr<Node> father_ = nullptr;
};


#endif//SLEKTSTRE_NODE_HPP
