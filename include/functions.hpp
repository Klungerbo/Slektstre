//
// Created by Torstein on 28/04/2022.
//

#ifndef SLEKTSTRE_FUNCTIONS_HPP
#define SLEKTSTRE_FUNCTIONS_HPP
#include "string"
#include <chrono>
#include <ctime>
#include <ctime>   // localtime
#include <iomanip> // put_time
#include <iostream>//                    |   | |   |
#include <sstream> // stringstream
#include <string>
#include <utility>//                      |   |
#include <vector> //   Children ^            |


int enterAge(){
    int age;
    std::string input_s;
    std::getline(std::cin, input_s);
    std::cin>>age;
    return age;
}
int inputDigit(){
    int input;
    std::cin>>input;
    if(!std::isdigit(input)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"invalid number. try again: \n";
        inputDigit();
    }
    return input;
}

std::string enterGender(){
    std::string gender;
    if(gender == ("female") || gender == "male"){
        return gender;
    }
    else{std::cout<<"try again.";
    }
}
std::string enterName(){
    std::string name;
    std::getline(std::cin, name );
    return name;
}

/*int getCurrentYear() {
    auto currentDateTime= std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(currentDateTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    auto currentDateTime_s = ss.str();
    std::string currentYear_s;
    for(int i = 1; i>5; i++){
        currentYear_s+=(currentDateTime_s[i]);
    }
    int currentYear = stoi(currentYear_s);
    std::cout <<currentYear;
    return currentYear;
}*/
int getCurrentYear() {
    return 2022;
}

//void main_menu(node &currentNode);
//
//int inputToInt() {
//    std::string s;
//    std::getline(std::cin, s);
//    return stoi(s);
//}

void defaultMsg() {
    std::cout << "Invalid number. Try again: ";
}

//void select_parent(node &currentNode) {
//    if (currentNode.isRoot()) {
//        std::cout << "Current node have no parents. Returning to main menu. \n";
//
//    } else {
//        currentNode = *currentNode.getParent();
//    }
//}

#endif //SLEKTSTRE_FUNCTIONS_HPP
