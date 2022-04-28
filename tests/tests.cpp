//
// Created by Torstein on 21/04/2022.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/Node.hpp"

Person testPerson("Pål pil", 20, Person::Male);

TEST_CASE("TEST getName") {
    std::string nameAnswer = testPerson.getName();
    REQUIRE(nameAnswer == "Pål pil");
}

TEST_CASE("TEST getAge") {
    REQUIRE(testPerson.getAge() == 20);

}
TEST_CASE("TEST getParent"){
    Person testChild("testChild", 4, Person::Female);
    Node testNode(testPerson);

    REQUIRE(parentNode == testPerson);
}

TEST_CASE("TEST getChildren") {
    node testPersonChild("Pål Pil", 1, node::Female);
    testPerson.addChild(testPersonChild);
    REQUIRE(testPerson.getChildren()[0] == testPersonChild);

}

TEST_CASE("TEST getGender") {
    int gender = testPerson.getGender();
    REQUIRE(gender == node::Male);
}

TEST_CASE("TEST addChild") {
    node child("Petter Pil", 1, node::Male);
    testPerson.addChild(child);
    REQUIRE(testPerson.getChildren().size() == 1);
}



