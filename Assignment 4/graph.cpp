#include "graph.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "edge.hpp"
#include "node.hpp"

// Complete this
bool Graph::hasTripletClique() const {
  if (nodes_.size() < 3) return false;
  for(auto it1 : nodes_) {
    Node* node1 = it1.second; //node1
    for(auto it2 : node1->getNeighbors()) {
      Node* node2 = it2; //edge exists between node1--node2
      for(auto it3 : nodes_) {
        if(it3.second != node1 && it3.second != node2) {
          Node* node3 = it3.second; //node3 is not node1 or node2
          if(node3->getNeighbors().find(node1) != node3->getNeighbors().end() &&
          node3->getNeighbors().find(node2) != node3->getNeighbors().end()) { 
            //returns true if edge exists between node1--node3 and node2--node3
            return true;
          }
        } 
      }
    }
  }
  return false;
}

// Complete this
bool Graph::isConnected() const {
  //BFS Traversal
  std::list<Node*> queue;
  Node* first = nodes_.begin()->second;
  queue.push_back(first);
  first->setVisited(true);
  while(!queue.empty()) {
    Node* curr = queue.front();
    queue.pop_front();
    for(auto i : curr->getNeighbors()) {
      if(!i->isVisited()) {
        i->setVisited(true);
        queue.push_back(i);
      }
    }
  }
  //check if every node is visited
  //if any node is not visited, return false
  //else return true
  for(auto i : nodes_) {
    if(i.second->isVisited() == false) {
      return false;
    }
  }
  return true;
}

// Complete this
double Graph::getMinDistance(const std::string &nid1,
                             const std::string &nid2) const {
  assert(nodes_.size() >= 2);  // Must have at least 2 nodes
  // To do
  
  return INF;
}

// Optional: complete this
double Graph::getLongestSimplePath() const {
  assert(nodes_.size() >= 1);  // Must have at least 1 node
  // To do
  return 0.0;
}

Graph::Graph(bool directed) : directed_(directed){};

Graph::~Graph() {
  for (Edge *edge : edges_) delete edge;
  edges_.clear();
  for (auto it : nodes_) delete it.second;
  nodes_.clear();
}

bool Graph::isDirected() const {
  return directed_;
}

bool Graph::addNode(const std::string &nid) {
  Node *node = new Node(nid);
  bool inserted = nodes_.emplace(nid, node).second;
  if (!inserted) delete node;
  return inserted;
}

bool Graph::addEdge(const std::string &nid1, const std::string &nid2,
                    double weight) {
  auto it1 = nodes_.find(nid1);
  auto it2 = nodes_.find(nid2);
  if (it1 == nodes_.end() || it2 == nodes_.end()) return false;

  Node *node1 = it1->second;
  Node *node2 = it2->second;

  Edge *edge1 = new Edge(node2, weight);
  node1->addEdge(edge1);
  edges_.insert(edge1);
  if (!directed_) {
    Edge *edge2 = new Edge(node1, weight);
    node2->addEdge(edge2);
    edges_.insert(edge2);
  }
  return true;
}

std::string Graph::toString(const std::string &delimiter) const {
  std::vector<std::string> nids;
  nids.reserve(nodes_.size());
  for (auto it : nodes_) nids.push_back(it.first);
  std::sort(nids.begin(), nids.end());

  std::stringstream ss;
  // Iterate each node
  for (size_t i = 0; i < nids.size(); i++) {
    if (i > 0) ss << delimiter;
    ss << nids[i] << ": [";
    Node *node = nodes_.find(nids[i])->second;
    bool first = true;
    for (Node *neighbor : node->getNeighbors()) {
      if (first) {
        ss << neighbor->getID();
        first = false;
      } else {
        ss << ", " << neighbor->getID();
      }
    }
    ss << "]";
  }
  return ss.str();
}

void Graph::printGraph() const { std::cout << toString() << std::endl; }