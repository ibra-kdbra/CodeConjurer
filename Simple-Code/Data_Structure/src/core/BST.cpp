#include "ds/BST.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// Constructor
BST::BST() : root(nullptr) {}

// Destructor
BST::~BST() {
    clear(root);
}

// Helper to clear tree
void BST::clear(BST::Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

// Insert a value into the BST
void BST::insert(int val) {
    root = insertHelper(root, val);
}

BST::Node* BST::insertHelper(BST::Node* node, int val) {
    if (!node) return new BST::Node(val);

    if (val < node->value)
        node->left = insertHelper(node->left, val);
    else if (val > node->value)
        node->right = insertHelper(node->right, val);
    // No handling of duplicates for simplicity

    return node;
}

// Traversal methods
void BST::preorder(std::vector<int>& res, BST::Node* node) {
    if (!node) return;
    res.push_back(node->value);
    preorder(res, node->left);
    preorder(res, node->right);
}

void BST::inorder(std::vector<int>& res, BST::Node* node) {
    if (!node) return;
    inorder(res, node->left);
    res.push_back(node->value);
    inorder(res, node->right);
}

void BST::postorder(std::vector<int>& res, BST::Node* node) {
    if (!node) return;
    postorder(res, node->left);
    postorder(res, node->right);
    res.push_back(node->value);
}

// Public traversal methods that return results
std::vector<int> BST::preorder() {
    std::vector<int> res;
    preorder(res, root);
    return res;
}

std::vector<int> BST::inorder() {
    std::vector<int> res;
    inorder(res, root);
    return res;
}

std::vector<int> BST::postorder() {
    std::vector<int> res;
    postorder(res, root);
    return res;
}
