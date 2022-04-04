//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_H
#define SLEKTSTRE_MYTREE_H
#include <iostream>                      //                    |   | |   |
#include <utility>                        //                      |   |
#include <vector>                        //   Children ^            |
#include "string"

class node{
public:
    explicit node(std::string name): name_(std::move(name)){};

    void addChild(node& n){

        n.parent_ = this;
        children_.emplace_back(n);
    }

    auto getParent() const{
        return parent_;
    }

    auto getChildren()const {
        return children_;
    }
    bool hasParent() const{
        return parent_;
    }
    [[nodiscard]] bool isRoot() const{
        return parent_== nullptr;
    }
    [[nodiscard]] bool isLeaf() const{
        return children_.empty();
    }

    std::string getName() const{
        return name_;
    }
    void printChildren() const{
        for(int i =0;i<children_.size();i++){
            std::cout<<"nr. "<< i+1 <<" is: "<<children_[i].getName()<<std::endl;
        }
    }


private:
    std::string name_;
    std::vector<node> children_;
    node* parent_ = nullptr;
};

int inputToInt(){
    std::string s;
    std::getline(std::cin, s);
    return stoi(s);
}

void defaultMsg(){
    std::cout << "Invalid number. Try again: ";
}
void get_children(const node &currentNode)
{
    if (currentNode.isLeaf())
    {
        std::cout << "Current node have no children. select something else. \n";
    }
    else
    {
        currentNode.printChildren();
    }
}

void select_parent(node &currentNode)
{
    int selection;
    if (currentNode.isRoot())
    {
        std::cout << "Current node have no parents. select something else. \n";
        selection = inputToInt();
    }
    else
    {
        currentNode = *currentNode.getParent();
    }
}

void select_child(node &currentNode)
{
    int selection;
    if (currentNode.isLeaf())
    {
        std::cout << "Current node has no children. select something else. \n";
        selection = inputToInt();
    }
    else
    {
        std::cout << "Choose one of the following numbers: \n";
        currentNode.printChildren();
        selection = inputToInt();
        currentNode = currentNode.getChildren()[selection + 1];
    }
}

void select_person(node &currentNode)
{
    int selection;
    while (true)
    {

        std::cout << "1. Select parent \n"
                     "2. Select child.\n"
                     "3. Go back to menu";
        selection = inputToInt();
        switch (selection)
        {

            case 1:
            {
                select_parent(currentNode);
                break;
            }
            case 2:
            {
                select_child(currentNode);
                break;
            }
            case 3:
                return;
            default:
                defaultMsg();
        }
    }
}

void get_parent(node &currentNode)
{
    if (currentNode.isRoot())
    {
        std::cout << "Current node have no parents. select something else. \n";
    }
    else
    {
        std::cout << currentNode.getParent()->getName();
    }
}

void add_child(node &currentNode)
{
    std::string name;
    std::cout << "Type child name: " << std::endl;
    std::getline(std::cin, name);
    node n(name);
    currentNode.addChild(n);
}

void main_menu(node &currentNode)
{
    int selection;

    while (true)
    {
        std::cout << "Currently selected is " << currentNode.getName() << "." << std::endl;
        std::cout << "1. Change selected person\n"
                     "2. Get children\n"
                     "3. Get parent\n"
                     "4. Add child\n"
                     "5. Exit program\n";
        selection = inputToInt();

        switch (selection)
        {

            case 1:
            { // change selected person
                select_person(currentNode);
                break;
            }
            case 2:
            {
                get_children(currentNode);
                break;
            }
            case 3:
            {
                get_parent(currentNode);
                break;
            }
            case 4:
            { // addChild
                add_child(currentNode);
                break;
            }
            case 5:
                std::cout << "Exiting program...";
                return;
            default:
                defaultMsg();
        }
    }
}



#endif //SLEKTSTRE_MYTREE_H
