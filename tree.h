//
// Created by Torst on 15.03.2022.
//

#ifndef SLEKTSTRE_Node_H
#define SLEKTSTRE_Node_H


#include <string>
#include <vector>
#include <functional>
#include <iostream>

class Node{
public:
    explicit Node(std::string name) : name_(std::move(name)){}

    [[nodiscard]] std::string getName() const{
        return name_;
    }
    void add(Node& n){
        n.parent_ = this;
        children_.emplace_back(&n);
    }
    [[nodiscard]] bool isRoot() const{
        return parent_== nullptr;
    }
    [[nodiscard]] bool isLeaf() const{
        return children_.empty();
    }
    [[nodiscard]] bool hasParent() const{
        return parent_ != nullptr;
    }

    void traverseUpwards(const std::function<void(Node*)>& f){
        f(this);
        if(hasParent()){
            parent_->traverseUpwards(f);
                }
    }
    void traverseDepthFirst(const std::function<void(Node*)>& f){
        f(this);
        for(auto c: children_){
            c->traverseDepthFirst(f);
        }
    }

    void printChildren(){
        if(!isLeaf()){
            for ( auto a : children_){
                std::cout<<a->getName()<<std::endl;
            }

        }
    }


private:
    std::string name_;
    Node* parent_ = nullptr;
    std::vector<Node*> children_;
};




#endif //SLEKTSTRE_Node_H
