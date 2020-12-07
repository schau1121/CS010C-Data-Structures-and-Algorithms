#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <cstdio>
#include <string>

using namespace std;

class WordEntry {
 public:
  WordEntry(const string &word, unsigned long score);

  void addNewAppearance(unsigned long s);
  const string &getWord();
  double getAverage() const;

 private:
  string word_;
  size_t numAppearances_;
  unsigned long totalScore_;
};

#endif
