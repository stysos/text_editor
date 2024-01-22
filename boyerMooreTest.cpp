#include <gtest/gtest.h>

#include "boyerMoore.hpp"

TEST(BoyerMooreTest, SearchTest) {
  // Test case 1
  BoyerMoore bm1("abc");
  std::vector<int> result1 = bm1.search("abcabc");
  EXPECT_EQ(result1, std::vector<int>({0, 3}));

  BoyerMoore bm2("pattern");
  std::vector<int> result2 =
      bm2.search("This is a pattern matching example with a pattern");

  EXPECT_EQ(result2, std::vector<int>({10, 42}));
}

TEST(BoyerMooreTest, EmptyTest) {
  BoyerMoore bm("");
  std::vector<int> result = bm.search("hello");
  EXPECT_EQ(result, std::vector<int>({}));
}

TEST(BoyerMooreTest, NotPresent) {
BoyerMoore bm(" ");
std::vector<int> result = bm.search("hello");
EXPECT_EQ(result, std::vector<int>({}));
}