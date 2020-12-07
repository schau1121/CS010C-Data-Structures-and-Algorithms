#include <queue>

#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() : root_(nullptr) {}

AVLTree::~AVLTree() {
  if (root_) {
    queue<Node *> nodes;
    nodes.push(root_);
    while (!nodes.empty()) {
      Node *node = nodes.front();
      nodes.pop();
      if (node->left) nodes.push(node->left);
      if (node->right) nodes.push(node->right);
      delete node;
    }
  }
}

void AVLTree::insert(const string &val) {

}

int AVLTree::balanceFactor(Node *node) const {

}

void AVLTree::printBalanceFactors() const {

}

void AVLTree::rotate(Node *node, const string &val) {

}

Node *AVLTree::rotateLeft(Node *node) {

}

Node *AVLTree::rotateRight(Node *node) {

}

void AVLTree::visualizeTree(ofstream &, Node *node) const {

}

Node *AVLTree::findUnbalancedNode(Node *node, const string &val) const {

}

void AVLTree::printBalanceFactors(Node *node) const {

}

void AVLTree::visualizeTree(const string& outputFilename) const {
  ofstream outFS(outputFilename.c_str());
  if (!outFS.is_open()) {
    cout << "Error" << endl;
    return;
  }
  outFS << "digraph G {" << endl;
  visualizeTree(outFS, root_);
  outFS << "}";
  outFS.close();
  string jpgFilename =
      outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void AVLTree::visualizeTree(ofstream& outFS, Node* node) const {
  if (node) {
    if (node->left) {
      visualizeTree(outFS, node->left);
      outFS << node->data << " -> " << node->left->data << ";" << endl;
    }
    if (node->right) {
      visualizeTree(outFS, node->right);
      outFS << node->data << " -> " << node->right->data << ";" << endl;
    }
  }
}