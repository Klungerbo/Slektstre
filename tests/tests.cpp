//
// Created by Torstein on 21/04/2022.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/myTree.hpp"

node per("PER pil", 20, "male");

/*TEST_CASE("TEST CLASS NAME") {

    std::string nameAnswer = per.getName();

    std::string genderAnswer = per.getGender();

    REQUIRE(nameAnswer == "PER pil");

}

TEST_CASE("TEST CLASS AGE") {

    int ageAnswer = per.getAge();
    REQUIRE(ageAnswer == 20);
}


TEST_CASE("TEST CLASS GENDER") {

    int genderAnswer = per.getAge();
    REQUIRE(genderAnswer == 20);
}

TEST_CASE("TEST ADD CHILD") {
    node child("Petter Pil", 1, "male");
    per.addChild(child);
    REQUIRE(per.getChildren().size() == 1);
}

TEST_CASE("TEST GET CHILDREN") {
    node perChild("Pål Pil", 1, "male");
    per.addChild(perChild);
    REQUIRE(per.getChildren()[0] == per);

}*/

TEST_CASE("TEST GET CURRENT YEAR") {
    int currentYear = 2022;

    REQUIRE(currentYear == getCurrentYear());

}