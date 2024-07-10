#include <iostream>

using namespace std;

class BSTNode {
public:
    int key;
    BSTNode *left;
    BSTNode *rigth;

    BSTNode *creat_bstnode(int k) {
        BSTNode *node = new BSTNode;
        node->key = k;
        node->left = node->rigth = NULL;

        return node;
    };
};

class BST {
private:
    BSTNode *inserthelp(BSTNode *root, int key) {
        if (root == NULL) {
            return root->creat_bstnode(key);
        }
        
        if (root->key > key) {
            root->left = inserthelp(root->left, key);
        }
        
        else {
            root->rigth = inserthelp(root->rigth, key);
        }
        
        return root;
    };

public:
    BSTNode *root;
    int nodecount;

    BST() {
        root = NULL;
        nodecount = 0;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    }

    void preorder(BSTNode *rt) {
        if (rt != NULL) {
            cout << " " << rt->key;

            preorder(rt->left);
            preorder(rt->rigth);
        }
    };

    void inorder(BSTNode *rt) {
        if (rt != NULL) {

            inorder(rt->left);
            cout << " " << rt->key;
            inorder(rt->rigth);
        }
    };

    void postorder(BSTNode *rt) {
        if (rt != NULL) {
            postorder(rt->left);
            postorder(rt->rigth);
            cout << " " << rt->key;
        }
    };
};

int main() {
    int number;
    int element;

    BST tree;

    cin >> number;
    
    for (int i = 0; i < number; i++) {
        cin >> element;
        tree.insert(element);
    }
    
    cout << "Pre order :";
    tree.preorder(tree.root);
    cout << endl;

    cout << "In order  :";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Post order:";
    tree.postorder(tree.root);

    return 0;
}