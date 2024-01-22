#include "boyerMoore.hpp"

#include <iostream>
#include <string>
#include <vector>

BoyerMoore::BoyerMoore(const std::string& pattern) : pattern{pattern} {
  preProcessBadChar();
}

BoyerMoore::~BoyerMoore() {}

void BoyerMoore::preProcessBadChar() {
  int patternLength = pattern.length();
  badChar.resize(numberOfChars, patternLength);

  for (int i = 0; i < patternLength - 1; ++i) {
    badChar[pattern[i]] = patternLength - 1 - i;
  }
}

std::vector<int> BoyerMoore::search(const std::string& text) {
  std::vector<int> occurrences;

  int patternLength = pattern.length();
  int textLength = text.length();
  int i = 0;

  if (patternLength < 1) {
    return std::vector<int>({});
  }

  while (i <= textLength - patternLength) {
    int j = patternLength - 1;

    // Check for a match
    while (j >= 0 && pattern[j] == text[i + j]) {
      --j;
    }

    if (j < 0) {
      // Match found
      occurrences.push_back(i);

      // Move to the next possible match
      i += patternLength;
    } else {
      // Shift the pattern based on bad character heuristic
      int badCharShift = badChar[text[i + j]] - (patternLength - 1 - j);

      i += std::max(1, badCharShift);
    }
  }

  return occurrences;
}
