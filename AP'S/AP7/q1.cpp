#include <bits/stdc++.h>

using namespace std;

class BSTNode {
public:
    int key;
    BSTNode *left;
    BSTNode *right;

    BSTNode *create_bstnode(int k) {
        BSTNode *node = new BSTNode;
        node->key = k;
        node->left = node->right = NULL;

        return node;
    };
};

class BST {
private:
    BSTNode *root;
    int nodecount;

    BSTNode *inserthelp(BSTNode *root, int key) {
        if (root == NULL) {
            return root->create_bstnode(key);
        }

        if (root->key > key) {
            root->left = inserthelp(root->left, key);
        }

        else {
            root->right = inserthelp(root->right, key);
        }

        return root;
    };

public:
    BST() {
        root = NULL;
        nodecount = 0;
    };

    ~BST() {
        delete root;
        nodecount = 0;
    };

    BSTNode *getroot() {
        return root;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    };

    void preorder(BSTNode *rt) {
        if (rt != NULL) {
            cout << rt->key << ' ';

            preorder(rt->left);
            preorder(rt->right);
        }
    };

    void inorder(BSTNode *rt) {
        if (rt != NULL) {

            inorder(rt->left);
            cout << rt->key << ' ';
            inorder(rt->right);
        }
    };

    void postorder(BSTNode *rt) {
        if (rt != NULL) {
            postorder(rt->left);
            postorder(rt->right);
            cout << rt->key << ' ';
        }
    };
};

int main() {
    BST tree;

    int oper, number;
    cin >> oper;

    string operation;

    while (oper--) {
        cin >> operation;

        if (operation == "insert") {
            cin >> number;
            tree.insert(number);
        }

        else {
            if (operation == "pre") {
                tree.preorder(tree.getroot());
            }

            else if (operation == "in") {
                tree.inorder(tree.getroot());
            }

            else {
                tree.postorder(tree.getroot());
            }

            cout << '\n';
        }
    }

    return 0;
}