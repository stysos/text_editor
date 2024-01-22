#pragma once

#include <string>
#include <vector>

class BoyerMoore {
 public:
  BoyerMoore(const std::string& pattern);
  ~BoyerMoore();

  std::vector<int> search(const std::string& text);

 private:
  std::string pattern;
  static constexpr int numberOfChars = 256;
  std::vector<int> badChar;

  void preProcessBadChar();
};