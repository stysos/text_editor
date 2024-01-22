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
    badChar[pattern[i]] = m - 1 - i;
  }
}

std::vector<int> BoyerMoore::search(const std::string& text) {
  std::vector<int> occurrences;

  int m = pattern.length();
  int n = text.length();
  int i = 0;

  if (m < 1) {
    return std::vector<int>({});
  }

  while (i <= n - m) {
    int j = m - 1;

    // Check for a match
    while (j >= 0 && pattern[j] == text[i + j]) {
      --j;
    }

    if (j < 0) {
      // Match found
      occurrences.push_back(i);

      // Move to the next possible match
      i += m;
    } else {
      // Shift the pattern based on bad character heuristic
      int badCharShift = badChar[text[i + j]] - (m - 1 - j);

      i += std::max(1, badCharShift);
    }
  }

  return occurrences;
}
