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

    auto getParent(){
        return parent_;
    }
    auto getAmountOfChildren(){
        return children_.size();
    }
    auto getChildren(node& n){
        return children_;
    }

    std::string getName(){
        return name_;
    }
    friend std::ostream& operator<<(std::ostream&, const node&);

private:
    std::string name_;
    std::vector<node> children_;
    node* parent_ = nullptr;
};


#endif //SLEKTSTRE_MYTREE_H
