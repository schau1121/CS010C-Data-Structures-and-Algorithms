#ifndef AVLTREE_H
#define AVLTREE_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

typedef struct Node {
  string data;
  unsigned int count;  // Increment if the same data is inserted.
  Node* left;
  Node* right;

  Node(const string &data)
      : data(data), count(1), left(nullptr), right(nullptr) {}
  int getHeight();
  void setHeight(int height);
  void setLeft(Node* l);
  void setRight(Node* r);
  Node* getLeft();
  Node* getRight();
} Node;

class AVLTree {
 public:
  AVLTree();
  ~AVLTree();

  void insert(const string &val);
  void visualizeTree(const string &val) const;
  int balanceFactor(Node *node) const;
  void printBalanceFactors() const;

 private:
  Node *root_;
  int height(Node* node);
  void rotate(Node *node, const string &val);
  Node *rotateLeft(Node *node);
  Node *rotateRight(Node *node);
  void visualizeTree(ofstream &, Node *node) const;
  Node *findUnbalancedNode(Node *node, const string &val) const;
  void printBalanceFactors(Node *node) const;
};

#endif