#include "MyTree.h"

MyTree::MyTree() : root_(nullptr), numNodes_(0) {
  // Initialize the tree without a root (empty tree)
}

MyTree::~MyTree() {
  // Delete all nodes except the root
  if (root_) {
    // Delete the root
    delete root_;
  }
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
}

BinaryNode *MyTree::Insert(const std::string &s, int x) {
    BinaryNode *node = new BinaryNode(s, x);
    if(root_ == nullptr) {
        root_ = node;
        numNodes_++;
    }
    else if(numNodes_ > 0) {
        int parentNodeLoc = ((numNodes_ + 1) / 2); //ceiling of numNodes / 2 gives parent location
        BinaryNode* curr = NodeAt(root_, parentNodeLoc);
        if(curr->left == nullptr) {
            curr->left = node;
            node->parent = curr;
            numNodes_++;
        }
        else if(curr->right == nullptr) {
            curr->right = node;
            node->parent = curr;
            numNodes_++;
        }
    }
    return node;
}

void MyTree::Preorder() const {
    if(root_ == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    }
    std::cout << "\nPrinting Tree in preorder..." << std::endl;
    PrintPreorder(root_);
    std::cout << std::endl;
}

BinaryNode *MyTree::FindMax() const {
    return MaxNode(root_);
}

void MyTree::MakeBST() {
    if(root_ == nullptr) {
        return;
    }
    std::vector<std::pair<int, std::string>> dataVector;
    StoreInOrder(root_, dataVector);
    std::sort(dataVector.begin(), dataVector.end());
    int i = 0;
    VectorToBST(dataVector, root_, i);
}

bool MyTree::FullChildren(BinaryNode* node) {
    bool full = false;
    if(node->left != nullptr && node->right != nullptr) {
        full = true;
    } 
    return full;
}

void MyTree::PrintPreorder(BinaryNode* node) const {
    if(node == nullptr) {
        return;
    }
    std::cout << node->myString << " ";
    PrintPreorder(node->left);
    PrintPreorder(node->right);
}


BinaryNode* MyTree::NodeAt(BinaryNode* root, int pos) {
    std::string binaryString = "";
    while(pos > 0) {
        if(pos % 2 == 0) {
            binaryString += '0';
        }
        else if(pos % 2 == 1) {
            binaryString += '1';
        }
        pos /= 2;
    }
    std::reverse(binaryString.begin(), binaryString.end());
    size_t i = 1;
    BinaryNode* curr = root;
    while(i < binaryString.size() && (curr->left != nullptr && curr->right != nullptr)) {
        if(binaryString[i] == '0') {
            curr = curr->left;
        }
        else if(binaryString[i] == '1') {
            curr = curr->right;
        }
    }
    return curr;
}

void MyTree::StoreInOrder(BinaryNode* root, std::vector<std::pair<int, std::string>>& inorder) {
    if(root == nullptr) {
        return;
    }

    StoreInOrder(root->left, inorder);
    inorder.push_back(std::make_pair(root->myInt, root->myString));
    StoreInOrder(root->right, inorder);
}

void MyTree::VectorToBST(std::vector<std::pair<int, std::string>> inorder, BinaryNode* root, int& i) {
    if(root == nullptr) {
        return;
    }
    VectorToBST(inorder, root->left, i);
    root->myInt = inorder.at(i).first;
    root->myString = inorder.at(i).second;
    i++;
    VectorToBST(inorder, root->right, i);
}

void MyTree::Inorder() const {
    PrintInorder(root_);
}

void MyTree::PrintInorder(BinaryNode* root) const {
    if(root == nullptr) {
        return;
    } 

    PrintInorder(root->left);
    std::cout << root->myInt << " ";
    PrintInorder(root->right);
}

BinaryNode* MyTree::MaxNode(BinaryNode* root) const {
    if(root == nullptr) {
        return nullptr;
    }
    else {
        BinaryNode* max = root;
        BinaryNode* lmax = nullptr;
        BinaryNode* rmax = nullptr;
        if(root->left != nullptr) {
            lmax = MaxNode(root->left);
        }
        if(root->right != nullptr) {
            rmax = MaxNode(root->right);
        }
        if(lmax != nullptr && lmax->myInt > max->myInt) {
            max = lmax;
        } 
        if(rmax != nullptr && rmax->myInt > max->myInt) {
            max = rmax;
        }
        return max;
        
    }
}