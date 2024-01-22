#include "boyerMoore.hpp"

#include <iostream>
#include <string>
#include <vector>

BoyerMoore::BoyerMoore(const std::string& pattern) : pattern{pattern} {
  preProcessBadChar();
}

BoyerMoore::~BoyerMoore() {}

void BoyerMoore::preProcessBadChar() {
  int m = pattern.length();
  badChar.resize(numberOfChars, m);

  for (int i = 0; i < m - 1; ++i) {
    badChar[static_cast<int>(pattern[i])] = m - 1 - i;
  }
}

std::vector<int> BoyerMoore::search(const std::string& text) {
  std::vector<int> occurrences;

  int m = pattern.length();
  int n = text.length();
  int i = 0;

  while (i <= n - m) {
    int j = m - 1;

    // Check for a match
    while (j >= 0 && pattern[j] == text[i + j]) {
      std::cout << "Matching characters: " << pattern[j] << " and "
                << text[i + j] << std::endl;
      --j;
    }

    if (j < 0) {
      // Match found
      occurrences.push_back(i);

      // Move to the next possible match
      i += m;
    } else {
      // Shift the pattern based on bad character heuristic
      int badCharShift = badChar[static_cast<int>(text[i + j])] - (m - 1 - j);
      i += std::max(1, badCharShift);
    }

    // Debug prints
    std::cout << "i: " << i << ", j: " << j << std::endl;
  }

  for (int pos : occurrences) {
    std::cout << pos << std::endl;
  }

  return occurrences;
}
