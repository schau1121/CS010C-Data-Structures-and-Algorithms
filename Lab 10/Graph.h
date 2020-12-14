#ifndef GRAPH_H
#define GRAPH_H

#include <climits>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
 public:
  Graph();
  Graph(istream &ins);
  ~Graph();

  size_t numVertices() const { return vertices_.size(); }
  size_t numEdges() const { return numEdges_; }

  bool add_vertex(const string &v);
  bool add_edge(const string &v1, const string &v2, unsigned int cost);
  void bfs();
  list<string> getVertices() const;
  unsigned int getDistance(const string &v) const;
  string getPrevious(const string &v) const;
  list<pair<string, unsigned int>> getNeighbors(const string &v) const;

  void output_graph(const string &outputFilename) const;

 private:
  typedef struct Vertex {
    // Neighbor vertex index and distance
    list<pair<size_t, unsigned int>> neighbors;
    string label;
    unsigned int distance;  // Distance from the start vertex
    size_t prev;            // Previous vertex index, SIZE_MAX if no previous vertex

    Vertex(const string &label = "")
        : label(label), distance(UINT_MAX), prev(SIZE_MAX) {}
  } Vertex;

  vector<Vertex> vertices_;
  size_t numEdges_;
  unordered_map<string, size_t> names_;
  
  static bool isValidVertexName(const string &name);
  void visualizeTree(ostream &outs) const;
};

#endif /* GRAPH_H */