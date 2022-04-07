//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_H
#define SLEKTSTRE_MYTREE_H

#include <vector>
#include "myTree.cpp"
class node{
public:
    explicit node(std::string name): name_(std::move(name)){};
    void addChild(node& n);
    auto getParent() const;
    auto getChildren()const ;
    [[nodiscard]] bool isRoot() const;
    [[nodiscard]] bool isLeaf() const;
    std::string getName() const;
    void printChildren() const;

private:
    std::string name_;
    std::vector<node> children_;
    node* parent_ = nullptr;
};

void main_menu(node &currentNode);
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
void showAll(node n);
void info_menu(node &currentNode);
void main_menu(node &currentNode);





#endif //SLEKTSTRE_MYTREE_H
