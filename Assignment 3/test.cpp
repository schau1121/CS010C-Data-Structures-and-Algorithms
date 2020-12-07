#include <chrono>
#include <time.h>
#include <stdlib.h>
#include "MyTree.h"

using namespace std;

string string_gen();
vector<pair<int, string>> randIntString(size_t size);
long long time_insert(size_t size);
long long time_preorder(size_t size);
long long time_findmax(size_t size);
long long time_makebst(size_t size);
// Testing (you must implement yours for the perfomance studies)
int main() {
  size_t size;
  cout << "Enter size of tree:" << endl;
  cin >> size;
  cout << "Times:" << endl;
  cout << "Build Tree -- " << time_insert(size) << " nanoseconds" << endl; 
  cout << "Find Max -- " << time_findmax(size) << " nanoseconds" << endl;
  cout << "Make BST -- " << time_makebst(size) << " microseconds" << endl;
  cout << "Preorder -- " << time_preorder(size) << " microseconds" << endl; 
  return 0;
}

string string_gen() {
  static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
  string curr;
  for(size_t i = 0; i < 10; i++) {
    curr += alphanum[rand() % (sizeof(alphanum) - 1)];
  }
  return curr;
}

vector<pair<int, string>> randIntString(size_t size) {
  vector<pair<int, string>> list;
  srand(time(0));
  for(size_t i = 0; i < size; i++) {
    int randNum = rand() % (size + 1);
    string randString = string_gen();
    list.push_back(make_pair(randNum, randString));
  }
  return list;
}

long long time_insert(size_t size) {
  size_t j;
  vector<pair<int, string>> currList = randIntString(size);
  auto start_time = chrono::high_resolution_clock::now();
  MyTree tree;
  for(j = 0; j < size; j++) {
    tree.Insert(currList.at(j).second, currList.at(j).first);
  }
  auto end_time = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
  return elapsed.count();
}


long long time_preorder(size_t size) {
  size_t j;
  vector<pair<int, string>> currList = randIntString(size);
  MyTree tree;
  for(j = 0; j < size; j++) {
    tree.Insert(currList.at(j).second, currList.at(j).first);
  }
  auto start_time = chrono::high_resolution_clock::now();
  tree.Preorder();
  auto end_time = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
  return elapsed.count();
}

long long time_findmax(size_t size) {
  size_t j;
  vector<pair<int, string>> currList = randIntString(size);
  MyTree tree;
  for(j = 0; j < size; j++) {
    tree.Insert(currList.at(j).second, currList.at(j).first);
  }
  auto start_time = chrono::high_resolution_clock::now();
  tree.FindMax();
  auto end_time = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
  return elapsed.count();
}

long long time_makebst(size_t size) {
  size_t j;
  vector<pair<int, string>> currList = randIntString(size);
  MyTree tree;
  for(j = 0; j < size; j++) {
    tree.Insert(currList.at(j).second, currList.at(j).first);
  }
  auto start_time = chrono::high_resolution_clock::now();
  tree.MakeBST();
  auto end_time = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
  return elapsed.count();
}
