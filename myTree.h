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
        std::cout << "Current node have no children. Select something else. \n";
    }
    else
    {
        currentNode.printChildren();
    }

}

void select_parent(node &currentNode)
{

    if (currentNode.isRoot())
    {
        std::cout << "Current node have no parents. Returning to main menu. \n";

    }
    else
    {
        currentNode = *currentNode.getParent();
    }
}

void select_child(node &currentNode)
{
    int selection=0;
    if (currentNode.isLeaf())
    {
        std::cout << "Current node has no children. Returning to main menu. \n";

    }
    else
    {
        std::cout << "Choose one of the following numbers: \n";
        currentNode.printChildren();
        selection = inputToInt();
        currentNode = currentNode.getChildren()[selection - 1];
    }
}

void select_person(node &currentNode)
{
    int selection;
    while (true)
    {

        std::cout << "\n1. Select parent \n"
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
        return;
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
node search(node n, std::string &name) {
    if (n.getName()!=name) {
        for (auto a: n.getChildren()) {
            if (a.getName() == name) {
                return a;
            } else if (!a.isLeaf()) {
                search(a, name);
            }
        }
    }
}
node search_person(node n){ //selects root, then iterates
    while (!n.isRoot()){
        n = *n.getParent();
    }
    std::cout<<"Enter person name: ";
    std::string name;
    std::getline(std::cin, name);
    search(n, name);
    }
    void showAll(node n){
        while (!n.isRoot()){
            n = *n.getParent();
        }
        std::cout<<n.getName()<<std::endl;

}





void main_menu(node &currentNode)
{
    int selection;
    while (true)
    {
        std::cout << "\nCurrently selected is " << currentNode.getName() << "." << std::endl;
        std::cout << "1. Change selected person\n"
                     "2. Show children\n"
                     "3. Show parent\n"
                     "4. Add child\n"
                     "5. Search for person\n"
                     "6. Exit program\n"
                     "7. Show all people";
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
            {
                search_person(currentNode);
                break;
            }

            case 6:
                std::cout << "Exiting program...";
                return;
            case 7:
            {

                break;
            }
            default:
                defaultMsg();
        }
    }
}



#endif //SLEKTSTRE_MYTREE_H
