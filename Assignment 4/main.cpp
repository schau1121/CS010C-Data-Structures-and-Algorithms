// g++ -std=c++11 graph.cpp main.cpp -o graph

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <ctime>

#include "graph.hpp"

typedef struct NodePair {
  size_t index1;
  size_t index2;

  NodePair(size_t i, size_t j) {
    assert(i != j);
    if (i < j) {
      index1 = i;
      index2 = j;
    } else {
      index1 = j;
      index2 = i;
    }
  }

  bool operator==(const NodePair& other) const {
    return index1 == other.index1 && index2 == other.index2;
  }
} NodePair;

// Make NodePair hashable
namespace std {
template <>
struct hash< NodePair > {
  inline size_t operator()(const NodePair& p) const {
    return hash<size_t>{}(p.index1) ^ hash<size_t>{}(p.index2);
  }
};
}  // namespace std

// Make NodePair hashable
template <>
struct std::equal_to<NodePair> {
  inline bool operator()(const NodePair& a, const NodePair& b) const {
    return a.index1 == b.index1 && a.index2 == b.index2;
  }
};

// Unique node names in sorted order
static std::vector<std::string> NODE_NAMES;
// Unique pairs of nodes as edges with the weights, no self-loop allowed
static std::unordered_map<NodePair, double> NODE_PAIRS;
// Random number using uniform distribution
static std::random_device RD;
static std::mt19937 GEN(RD());
static std::uniform_int_distribution<size_t> DIST;
std::string genName();
// Generate n unique node names
static void generateNodeNames(size_t n);
static size_t getRandomIndex();
// Generate m unique pairs of nodes as edges
static void generateNodePairs(size_t m, double weight);

int main() {
  generateNodeNames(100);
  generateNodePairs(500, 1.0);
  generateNodePairs(500, 2.0);
  generateNodePairs(500, 3.0);

  Graph graph(false);
  // Add nodes
  for (std::string name : NODE_NAMES) graph.addNode(name);
  // Add edges
  for (auto it : NODE_PAIRS) {
    graph.addEdge(NODE_NAMES[it.first.index1], NODE_NAMES[it.first.index2],
                  it.second);
  }
  graph.printGraph();

  auto start_time1 = std::chrono::steady_clock::now();
  graph.hasTripletClique();
  auto end_time1 = std::chrono::steady_clock::now();
  unsigned long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count();
  std::cout << "\nTime of hasTripletClique(): " << elapsed << "ns" << std::endl;


  auto start_time = std::chrono::high_resolution_clock::now();
  graph.isConnected();
  auto end_time = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
  std::cout << "Time of isConnected(): " << elapsed << "ns" << std::endl;

  srand(time(nullptr));
  std::string name1 = NODE_NAMES[rand() % (sizeof(NODE_NAMES) - 1)];
  std::string name2 = NODE_NAMES[rand() % (sizeof(NODE_NAMES) - 1)];
  start_time = std::chrono::high_resolution_clock::now();
  graph.getMinDistance(name1, name2);
  end_time = std::chrono::high_resolution_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
  std::cout << "Time of getMinDistance(): " << elapsed << "ns" << std::endl;

  return 0;
}

std::string genName() {
  srand(time(nullptr));
  std::string tmp = "";
  const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  tmp.reserve(3);
  for(int i = 0; i < 3; i++) {
    tmp += alpha[rand() % (sizeof(alpha) - 1)];
  }
  return tmp;
}

static void generateNodeNames(size_t n) {
  assert(n > 0);
  assert(NODE_NAMES.empty());
  std::unordered_set<std::string> names;
  names.reserve(n);
  while (names.size() < n) {
    std::string name = genName(); 
    names.insert(name);     // Insert will fail for duplicate names
  }
  NODE_NAMES.reserve(n);
  for (std::string name : names) NODE_NAMES.push_back(name);
  std::sort(NODE_NAMES.begin(), NODE_NAMES.end());
}

static size_t getRandomIndex() {
  assert(!NODE_NAMES.empty());
  if (DIST.a() != 0 || DIST.b() != NODE_NAMES.size() - 1) {
    decltype(DIST.param()) range(0, NODE_NAMES.size() - 1);
    DIST.param(range);
  }
  return DIST(GEN);
}

static void generateNodePairs(size_t m, double weight) {
  assert(m > 0);
  assert(weight > 0.0);
  assert(weight < Graph::INF);

  size_t original = NODE_PAIRS.size();
  NODE_PAIRS.reserve(original + m);
  while (NODE_PAIRS.size() - original < m) {
    // Randomly pick 2 distinct names
    size_t i = getRandomIndex();
    size_t j = getRandomIndex();
    while (i == j) j = getRandomIndex();
    // If a pair of nodes of these 2 names already exists, insert will fail
    if (i < j) {
      NODE_PAIRS.insert({NodePair(i, j), weight});
    } else {
      NODE_PAIRS.insert({NodePair(j, i), weight});
    }
  }
}