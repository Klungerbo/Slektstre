//
// Created by Torst on 14.03.2022.
//

#include <iostream>
#include "tree.h"

int main(){
   Node root("root");
   Node child1("child 1");
   Node child2("child 2");
   Node child3("child 3");
   root.add(child1);
   root.add(child2);
   root.add(child3);
   root.showChildren();
       return 1;
}