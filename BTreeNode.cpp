#include <iostream>
using namespace std;

class BTreeNode {
public:
    int key;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int k) {
        key = k;
        left = right = nullptr;
    }
};

class BTree {
public:
    BTreeNode* root;

    BTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    BTreeNode* insertRec(BTreeNode* node, int key) {
        if (node == nullptr) {
            return new BTreeNode(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }

        return node;
    }

    void display(BTreeNode* node) {
        if (node != nullptr) {
            display(node->left);
            cout << node->key << " ";
            display(node->right);
        }
    }

    void printTree() {
        display(root);
        cout << endl;
    }
};

int main() {
    BTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "B-Tree Structure:" << endl;
    tree.printTree();

    return 0;
}
