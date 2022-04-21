//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_HPP
#define SLEKTSTRE_MYTREE_HPP

#include <vector>
#include "myTree.cpp"

class node {
public:
    explicit node(std::string name);

    explicit node(std::string name, int age);

    explicit node(std::string name, int age, std::string gender);

    void addChild(node &n);

    auto getParent() const;

    auto getChildren() const;

    void setAge();

    void setGender();

    void setName();

    [[nodiscard]] bool isRoot() const;

    [[nodiscard]] bool isLeaf() const;

    std::string getName() const;

    void printChildren() const;

    std::string getGender() const;

    int getAge() const;

private:
    std::string name_;
    std::vector<node> children_;
    node *parent_ = nullptr;
    std::string gender_;
    int age_ = 0;
};

int inputToInt();

void defaultMsg();

void get_children(const node &currentNode);

void select_parent(node &currentNode);

void select_child(node &currentNode);

void select_person(node &currentNode);

void get_parent(node &currentNode);

void add_child(node &currentNode);

void search(node &sNode, std::string &name);

node search_person(node &currentNode);


void info_menu(node &currentNode);

void main_menu(node &currentNode);


#endif //SLEKTSTRE_MYTREE_HPP
