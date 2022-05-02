//
// Created by Torstein on 21/04/2022.
//
#define CATCH_CONFIG_MAIN

#include "../include/Node.hpp"
#include "catch.hpp"

Person testPerson("Pål pil", 20, Person::Male);
Node testNode(testPerson);

TEST_CASE("TEST Person.getName") {
    std::string nameAnswer = testPerson.getName();
    REQUIRE(nameAnswer == "Pål pil");
}

TEST_CASE("TEST Person.getAge") {
    REQUIRE(testPerson.getAge() == 20);
}

TEST_CASE("TEST Person.getGender") {
    REQUIRE(testPerson.getGender() == Person::Male);
}

TEST_CASE("TEST Node.getParent") {
    Person testChild("testChild", 4, Person::Female);
    testNode.addParent(testChild);
    REQUIRE(testNode.getParent(0) == testChild);
}


