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
    int getAmountOfChildren() const{
        return children_.size();
    }
    auto getChildren(){
        return children_;
    }

    std::string getName() const{
        return name_;
    }


private:
    std::string name_;
    std::vector<node> children_;
    node* parent_ = nullptr;
};
/*std::ostream& operator << (std::string& stream, node n){
    for(auto a: n.getChildren()){
        std::string name = a.getName();
        stream << name <<"\n";
    }
}*/



#endif //SLEKTSTRE_MYTREE_H
