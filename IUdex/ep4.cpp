#include <iostream>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode *create_avl_node(int k) {
        AVLNode *temp = new AVLNode;
        temp->key = k;
        temp->height = 0;
        temp->left = temp->right = NULL;

        return temp;
    }
};

class AVL {
private:
    AVLNode *root;
    int nodecount;

    int max(int numb1, int numb2) {
        if (numb1 >= numb2) {
            return numb1;
        }
        
        return numb2;
    };

    int height(AVLNode *rt) {
        if (rt == NULL) {
            return -1;
        }
        
        return rt->height;
    };

    int getbalance(AVLNode *rt) {
        if (rt == NULL) {
            return 0;
        }
        
        return (height(rt->left) - height(rt->right));
    };

    AVLNode *right_rotate(AVLNode *rt) {
        AVLNode *temp_left = rt->left;
        AVLNode *temp_left_right = temp_left->right;

        temp_left->right = rt;
        rt->left = temp_left_right;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        temp_left->height = max(height(temp_left->left), height(temp_left->right)) + 1;

        return temp_left;
    };

    AVLNode *left_rotate(AVLNode *rt) {
        AVLNode *temp_right = rt->right;
        AVLNode *temp_right_left = temp_right->left;

        temp_right->left = rt;
        rt->right = temp_right_left;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        temp_right->height = max(height(temp_right->left), height(temp_right->right)) + 1;

        return temp_right;
    };

    AVLNode *inserthelp(AVLNode *rt, int key) {
        if (rt == NULL) {
            return rt->create_avl_node(key);
        }

        if (rt->key > key) {
            rt->left = inserthelp(rt->left, key);
        }
        
        else {
            rt->right = inserthelp(rt->right, key);
        }
        
        rt->height = 1 + max(height(rt->left), height(rt->right));
        int balance = getbalance(rt);

        if (balance < -1 && key >= rt->right->key) {
            return left_rotate(rt);
        }
        
        else if (balance > 1 && key < rt->left->key) {
            return right_rotate(rt);
        }
        
        else if (balance > 1 && key >= rt->left->key) {
            rt->left = left_rotate(rt->left);
            return right_rotate(rt);
        }

        else if (balance < -1 && key < rt->right->key) {
            rt->right = right_rotate(rt->right);
            return left_rotate(rt);
        }
        
        return rt;
    }

public:
    AVL() {
        root = NULL;
        nodecount = 0;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    };

    AVLNode *get_root() {
        return root;
    }

    void preorder(AVLNode *rt) {
        if (rt != NULL) {
            cout << rt->key << '\n';

            preorder(rt->left);
            preorder(rt->right);   
        }
    }
};


int main() {
    int cases;

    cin >> cases;

    int element;

    for (int i = 0; i < cases; i++) {
        AVL tree;
        int number;

        cin >> element;

        for (int j = 0; j < element; j++) {
            cin >> number;

            tree.insert(number);
        }
        
        tree.preorder(tree.get_root());
        cout << "END" << '\n';
    }

    return 0;
}