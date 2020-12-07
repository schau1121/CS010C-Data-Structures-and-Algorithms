#include "HashTable.h"

/* HashTable constructor
 *  input s is the size of the array
 *  set s to be size
 *  initialize array of lists of WordEntry
 */
HashTable::HashTable(size_t size)
    : hashTable_(new list<WordEntry>[size]), size_(size) {}

HashTable::~HashTable() {
  for (size_t i = 0; i < size_; i++) hashTable_[i].clear();
  delete [] hashTable_;
}

/* computeHash
 *  return an unsigned integer based on the input string
 *  used for index into the array in hash table
 *  be sure to use the size of the array to ensure array
 *  index doesn't go out of bounds
 */
//followed geeksforgeeks implentation for string hashing
size_t HashTable::computeHash(const string &s) const { 
  size_t p = 53;
  size_t m = 1e9 + 9;
  long long power_of_p = 1;
  long long hash_val = 0;

  for(size_t i = 0; i < s.length(); i++) {
    hash_val = (hash_val + (s[i] - 'a' + 1) * power_of_p) % m;
    power_of_p = (power_of_p * p) % m;
  }
  return (hash_val % size_);
}

/* put
 *  input: string word and int score to be inserted
 *  First, look to see if word already exists in hash table
 *   if so, addNewAppearence with the score to the WordEntry
 *   if not, create a new Entry and push it on the list at the
 *   appropriate array index
 */
void HashTable::put(const string &s, unsigned long score) {
  size_t hash_val = computeHash(s);
  if(contains(s)) {
    for(auto &hashItem : hashTable_[hash_val]) {
      if(hashItem.getWord() == s) {
        hashItem.addNewAppearance(score);
        break;
      }
    }
  } 
  else {
    hashTable_[hash_val].emplace_back(s, score);
  }
}

/* getAverage
 *  input: string word
 *  output: the result of a call to getAverage()
 *          from the WordEntry
 *  Must first find the WordEntry in the hash table
 *  then return the average
 *  If not found, return the value 2.0 (neutral result)
 */

double HashTable::getAverage(const string &s) const {
  if(contains(s) == false) {
    return 2.0;
  }
  else {
    size_t hash_val = computeHash(s);
    for(auto hashItem : hashTable_[hash_val]) {
      if(hashItem.getWord() == s) {
        return hashItem.getAverage();
      }
    }
  }
}

/* contains
 * input: string word
 * output: true if word is in the hash table
 *         false if word is not in the hash table
 */
bool HashTable::contains(const string &s) const {
  size_t hash_val = computeHash(s);
  for(auto hashItem : hashTable_[hash_val]) {
    if(hashItem.getWord() == s) {
      return true;
    }
  }
  return false;
}

