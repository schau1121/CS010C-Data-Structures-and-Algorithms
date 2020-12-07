#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdio>
#include <list>
#include <string>

#include "WordEntry.h"

using namespace std;

class HashTable {
 public:
  HashTable(size_t size);
  ~HashTable();

  bool contains(const string &s) const;
  double getAverage(const string &s) const;
  void put(const string &s, unsigned long score);

 private:
  // It's better to return an unsigned integer, you may use unsigned int.
  size_t computeHash(const string &s) const;

  list<WordEntry> *hashTable_;
  size_t size_;
};

#endif
