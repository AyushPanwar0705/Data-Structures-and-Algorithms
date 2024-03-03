#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insertRecursive(node->left, key);
        else if (key > node->key) node->right = insertRecursive(node->right, key);
        return node;
    }

    Node* searchRecursive(Node* node, int key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return searchRecursive(node->left, key);
        return searchRecursive(node->right, key);
    }

    void inorderTraversalRecursive(Node* node) {
        if (node) {
            inorderTraversalRecursive(node->left);
            std::cout << node->key << " ";
            inorderTraversalRecursive(node->right);
        }
    }

    Node* deleteRecursive(Node* node, int key) {
        if (!node) return node;
        if (key < node->key) node->left = deleteRecursive(node->left, key);
        else if (key > node->key) node->right = deleteRecursive(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            node->key = findMinValue(node->right);
            node->right = deleteRecursive(node->right, node->key);
        }
        return node;
    }

    int findMinValue(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node->key;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    bool search(int key) {
        return searchRecursive(root, key) != nullptr;
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal:" << std::endl;
    bst.inorderTraversal();  // Should print 20 30 40 50 60 70 80

    int searchKey = 40;
    std::cout << "Search for key " << searchKey << ": ";
    if (bst.search(searchKey)) {
        std::cout << "Key " << searchKey << " found" << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found" << std::endl;
    }

    int deleteKey = 30;
    bst.remove(deleteKey);
    std::cout << "Inorder Traversal after deleting " << deleteKey << ":" << std::endl;
    bst.inorderTraversal();  // Should print 20 40 50 60 70 80

    return 0;
}
