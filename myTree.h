//
// Created by Torst on 22.03.2022.
//

#ifndef SLEKTSTRE_MYTREE_H
#define SLEKTSTRE_MYTREE_H
#include <iostream>                      //                    |   | |   |
#include <utility>                        //                      |   |
#include <vector>                        //   Children ^            |

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



int menuInput(){
    std::string s;
    std::getline(std::cin, s);

    return std::stoi(s);
}
void defaultMsg(){
    std::cout << "Invalid number. Try again: ";
}


#endif //SLEKTSTRE_MYTREE_H
