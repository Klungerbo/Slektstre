//
// Created by Torstein on 22/04/2022.
//

#ifndef SLEKTSTRE_CONSOLE_HPP
#define SLEKTSTRE_CONSOLE_HPP

#include "Node.hpp"

int enterAge(){
    int age;
    std::cout<<"enter age: "<<std::endl;
    std::cin>>age;
}
std::string enterGender(){
    std::string gender;
    std::cout<<"enter gender: "<<std::endl;
    if(gender == ("female") || gender == "male"){
        return gender;
    }
    else{std::cout<<"try again.";
    }
}
std::string enterName(){
    std::string name;
    std::cout<<"enter name: "<<std::endl;
}

#endif //SLEKTSTRE_CONSOLE_HPP
