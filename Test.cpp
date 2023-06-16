/*
# Copyright (c) https://github.com/alenanish/devops_lab1 . All rights reserved.
*/
#include <iostream>
#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(MergeTwoListsTest, Test1) {
  ASSERT_EQ(countNodes(5), 5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
