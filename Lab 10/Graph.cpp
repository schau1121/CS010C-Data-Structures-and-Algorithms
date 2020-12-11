#include "Graph.h"

#include <cstring>  // for memset
#include <fstream>
#include <queue>

Graph::Graph() : numEdges_(0) {}

Graph::Graph(istream& ins) : numEdges_(0) {
  size_t numVertices;
  size_t numEdges;
  ins >> numVertices;
  ins >> numEdges;
  vertices_.reserve(numVertices);
  names_.reserve(numVertices);
  for (size_t i = 0; i < numVertices; i++) {
    string name;
    ins >> name;
    if (add_vertex(name)) cout << i << ") " << name << endl;
  }
  for (size_t i = 0; i < numEdges; i++) {
    string v1;
    string v2;
    unsigned int cost;
    ins >> v1 >> v2 >> cost;
    if (add_edge(v1, v2, cost)) {
      cout << names_[v1] << " -> " << names_[v2] << ": " << cost << endl;
    }
  }
  cout << vertices_.size() << " "
       << (vertices_.size() < 2 ? "vertex" : "vertices") << " and " << numEdges_
       << " " << (numEdges_ < 2 ? " edge" : "edges") << endl;
}

Graph::~Graph() {
  vertices_.clear();
  names_.clear();
}

bool Graph::add_vertex(const string& v) {
  // Implement here
  // Return true if the vertex can be added, otherwise return false (vertex name
  // is invalid or a vertex with the same name already exists).
}

bool Graph::add_edge(const string& v1, const string& v2, unsigned int cost) {
  // Implement here
  // Return true if the edge can be added, otherwise return false (either vertex
  // cannot be found, or the cost is 0 or UINT_MAX).
  // Remember to increment numEdges_.
}

void Graph::bfs() {
  // Implement BFS here
  // You are NOT allowed to modify Vertex.
}

list<string> Graph::getVertices() const {
  list<string> ret;
  for (vector<Vertex>::const_iterator it = vertices_.begin();
       it != vertices_.end(); ++it) {
    ret.push_back(it->label);
  }
  return ret;
}

unsigned int Graph::getDistance(const string& v) const {
  unordered_map<string, size_t>::const_iterator it = names_.find(v);
  if (it == names_.end()) return UINT_MAX;
  return vertices_[it->second].distance;
}

string Graph::getPrevious(const string& v) const {
  unordered_map<string, size_t>::const_iterator it = names_.find(v);
  if (it == names_.end()) return "";
  size_t prev = vertices_[it->second].prev;
  if (prev >= 0 && prev < vertices_.size()) return vertices_[prev].label;
  return "";
}

list<pair<string, unsigned int>> Graph::getNeighbors(const string& v) const {
  list<pair<string, unsigned int>> ret;
  unordered_map<string, size_t>::const_iterator it = names_.find(v);
  if (it == names_.end()) return ret;
  for (pair<size_t, unsigned int> neighbor : vertices_[it->second].neighbors) {
    ret.emplace_back(vertices_[neighbor.first].label, neighbor.second);
  }
  return ret;
}

void Graph::output_graph(const string& outputFilename) const {
  ofstream outFS(outputFilename.c_str());
  if (!outFS.is_open()) {
    cout << "Error" << endl;
    return;
  }
  visualizeTree(outFS);
  outFS.close();
  string jpgFilename =
      outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void Graph::visualizeTree(ostream& outs) const {
  if (vertices_.empty()) {
    outs << "digraph G {}" << endl;
    return;
  };
  if (vertices_.size() == 1) {
    outs << "digraph G {" << endl;
    outs << vertices_[0].label << "[label=\"" << vertices_[0].label << ", "
         << vertices_[0].distance << "\", fillcolor = white];" << endl;
    outs << "}" << endl;
    return;
  }

  queue<size_t> q;
  short* colors = new short[vertices_.size()];
  memset(colors, 0, sizeof(short) * vertices_.size());
  colors[0] = 1;
  q.push(0);

  outs << "digraph G {" << endl;
  while (!q.empty()) {
    size_t i = q.front();
    q.pop();
    outs << "  " << vertices_[i].label << "[label=\"" << vertices_[i].label
         << ", " << vertices_[i].distance << "\", style=filled, fillcolor="
         << (colors[i] == 1 ? "white" : "yellow") << "];" << endl;
    for (list<pair<size_t, unsigned int>>::const_iterator it =
             vertices_[i].neighbors.begin();
         it != vertices_[i].neighbors.end(); ++it) {
      size_t n = it->first;
      outs << "  " << vertices_[i].label << " -> " << vertices_[n].label
           << "[label=\"" << it->second << "\"];" << endl;
      if (colors[n] == 0) {
        q.push(n);
        colors[n] = colors[i] == 1 ? 2 : 1;
      }
    }
  }
  outs << "}" << endl;
  delete[] colors;
}

bool Graph::isValidVertexName(const string& name) {
  if (name.empty() || name.length() > 15) return false;
  for (char c : name) {
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') || c == '_'))
      return false;
  }
  return true;
}
