//
// Created by Torstein on 28/04/2022.
//

#ifndef SLEKTSTRE_PERSON_HPP
#define SLEKTSTRE_PERSON_HPP
#include "functions.hpp"

class Person {
public:
    enum Gender {
        Male,
        Female,
        Empty
    };

    explicit Person(std::string name, int age = 0, Gender gender = Empty) : name_(std::move(name)), age_(age),
                                                                            gender_(gender), ID_(ID_counter++) {};

    void setAge(int age) {
        age_ = age;
        birthYear_ = getCurrentYear() - age_;
    }

    [[nodiscard]] int getAge() const {
        return getCurrentYear() - birthYear_;
    }


    void setGender(Gender &g) {
        gender_ = g;
    }

    void setName(std::string &name) {
        name_ = name;
    }


    [[nodiscard]] bool isFemale() const {
        return gender_ == Female;
    }

    [[nodiscard]] bool isMale() const {
        return gender_ == Male;
    }

    [[nodiscard]] std::string getName() const {
        return name_;
    }

    [[nodiscard]] int getBirthYear() const {
        return birthYear_;
    }
    int getID()const{
        return ID_;
    }

    [[nodiscard]] int getGender() const {
        if (gender_ == Male) {
            return Male;
        } else {
            return Female;
        }
    }
    [[nodiscard]] std::string getGender_s() const {
        if (gender_ == Male) {
            return "Male";
        } else {
            return "Female";
        }
    }

    bool operator==(const Person &a) const {

        if (a.ID_ == ID_) {
            return true;
        } else {
            return false;
        }
    }

private:
    std::string name_;
    int gender_ = Male;
    int age_ = 0;
    int ID_ = 0;
    int birthYear_ = getCurrentYear() - age_;
    static int ID_counter;
};
int Person::ID_counter=0;


#endif //SLEKTSTRE_PERSON_HPP
