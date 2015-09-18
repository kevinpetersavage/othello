#include "google/gtest/include/gtest/gtest.h"

int sum(int a, int b) {return a+b;}

TEST(Sum, Normal) {
  EXPECT_EQ(5, sum(2, 3));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
