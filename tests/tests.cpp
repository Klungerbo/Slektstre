//
// Created by Torstein on 21/04/2022.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/myTree.hpp"

node testNode("Pål pil", 20, node::Male);

TEST_CASE("TEST getName") {
    std::string nameAnswer = testNode.getName();
    REQUIRE(nameAnswer == "Pål pil");
}

TEST_CASE("TEST getAge") {
    REQUIRE(testNode.getAge() == 20);

}
TEST_CASE("TEST getParent"){
    node testNodeChild("testChild", 4, node::Female);
    testNode.addChild(testNodeChild);
    node parentNode = *testNodeChild.getParent();
    REQUIRE(parentNode == testNode);
}

TEST_CASE("TEST getChildren") {
    node testNodeChild("Pål Pil", 1, node::Female);
    testNode.addChild(testNodeChild);
    REQUIRE(testNode.getChildren()[0] == testNodeChild);

}

TEST_CASE("TEST getGender") {
    int gender = testNode.getGender();
    REQUIRE(gender == node::Male);
}

TEST_CASE("TEST addChild") {
    node child("Petter Pil", 1, node::Male);
    testNode.addChild(child);
    REQUIRE(testNode.getChildren().size() == 1);
}



