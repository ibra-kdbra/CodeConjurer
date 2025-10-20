#ifndef BST_H
#define BST_H

#include <vector>

class BST {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    BST();
    ~BST();
    void insert(int val);
    std::vector<int> preorder();
    std::vector<int> inorder();
    std::vector<int> postorder();

private:
    Node* insertHelper(Node* node, int val);
    void clear(Node* node);
    void preorder(std::vector<int>& res, Node* node);
    void inorder(std::vector<int>& res, Node* node);
    void postorder(std::vector<int>& res, Node* node);
};

#endif // BST_H
