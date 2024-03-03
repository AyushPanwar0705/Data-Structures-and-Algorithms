#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void sort() {
        std::cout << "Sorted order: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST bst;

    // Insertion
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Sorting
    bst.sort();

    // Deletion
    bst.remove(20);
    bst.remove(30);

    // Sorting after deletion
    bst.sort();

    return 0;
}
