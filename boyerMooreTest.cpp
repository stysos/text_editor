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

  // Debug prints
  std::cout << "Pattern: "
            << "pattern" << std::endl;  // Directly print the pattern
  std::cout << "Text: "
            << "This is a pattern matching example with a pattern" << std::endl;
  std::cout << "Actual Result: ";
  for (int pos : result2) {
    std::cout << pos << " ";
  }
  std::cout << std::endl;
  EXPECT_EQ(result2, std::vector<int>({10, 42}));

  // Add more test cases as needed
}