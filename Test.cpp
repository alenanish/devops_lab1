/*
# Copyright (c) https://github.com/alenanish/devops_lab1 . All rights reserved.
*/
#include <iostream>
#include "LinkedList.hpp"
#include "gtest/gtest.h"

TEST(MergeTwoListsTest, Test) {
  ASSERT_EQ(mergeTwoLists(2, 2), "0->1->2->3->nullptr");
}

TEST(ReverseListTest, Test) {
  ASSERT_EQ(reverseList(4), "6->4->2->0->nullptr");
}

TEST(CountNodesTest, Test) {
  ASSERT_EQ(countNodes(4), 4);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
