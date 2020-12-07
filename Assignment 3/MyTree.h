#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <bitset>

typedef struct BinaryNode {
  std::string myString;
  int myInt;
  BinaryNode *parent;
  BinaryNode *left;
  BinaryNode *right;

  BinaryNode(const std::string &s, int x)
      : myString(s), myInt(x), parent(nullptr), left(nullptr), right(nullptr) {}
  ~BinaryNode();
} BinaryNode;

class MyTree {
 public:
  MyTree();
  ~MyTree();  // Delete all nodes in the tree

  size_t NumNodes() const { return numNodes_; };

  // Insert new node into first available position (to keep the tree almost
  // complete), return the created node.
  BinaryNode *Insert(const std::string &s, int x);

  // Output all strings in pre-order
  // all the strings will be print in one line separated by spaces
  void Preorder() const;

  // Returns a pointer to the node with maximum myInt
  BinaryNode *FindMax() const;

  // Converts the binary tree into a binary search tree (BST) with respect to
  // myInt. That is, move around node values (myString and myInt) to satisfy the
  // BST property.
  void MakeBST();

  void Inorder() const; //prints integers inorder to check if MakeBST works

  private:
  BinaryNode *root_;
  size_t numNodes_;
  bool FullChildren(BinaryNode* node);
  void StoreInOrder(BinaryNode* root, std::vector<std::pair<int, std::string>>& inorder);
  void PrintPreorder(BinaryNode* node) const; //prints strings preorder
  void PrintInorder(BinaryNode* root) const; //prints ints inorder
  void VectorToBST(std::vector<std::pair<int, std::string>> inorder, BinaryNode* root, int& i);
  BinaryNode* NodeAt(BinaryNode* root, int pos);
  BinaryNode* MaxNode(BinaryNode* root) const;
};

