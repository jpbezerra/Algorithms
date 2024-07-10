#include <iostream>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    int nodec;
    AVLNode *left;
    AVLNode *right;

    AVLNode *create_avlnode(int key) {
        AVLNode *node = new AVLNode;
        node->key = key;
        node->height = 0;
        node->nodec = 1;
        node->left = node->right = NULL;

        return node;
    };
};

class AVL {
private:
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

    int leftnodecount(AVLNode *rt) {
        if (rt->left != NULL) {
            return rt->left->nodec;
        }
        
        return 0;
    }

     int rightnodecount(AVLNode *rt) {
        if (rt->right != NULL) {
            return rt->right->nodec;
        }
        
        return 0;
    }

    AVLNode *right_rotate(AVLNode *rt) {
        AVLNode *temp_left = rt->left;
        AVLNode *temp_left_right = temp_left->right;

        temp_left->right = rt;
        rt->left = temp_left_right;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        rt->nodec = 1 + leftnodecount(rt) + rightnodecount(rt);
        temp_left->height = max(height(temp_left->left), height(temp_left->right)) + 1;
        temp_left->nodec = 1 + leftnodecount(temp_left) + rightnodecount(temp_left);

        return temp_left;
    };

    AVLNode *left_rotate(AVLNode *rt) {
        AVLNode *temp_right = rt->right;
        AVLNode *temp_right_left = temp_right->left;

        temp_right->left = rt;
        rt->right = temp_right_left;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        rt->nodec = 1 + leftnodecount(rt) + rightnodecount(rt);
        temp_right->height = max(height(temp_right->left), height(temp_right->right)) + 1;
        temp_right->nodec = 1 + leftnodecount(temp_right) + rightnodecount(temp_right);

        return temp_right;
    };

    AVLNode *inserthelp(AVLNode *rt, int key) {
        if (rt == NULL) {
            return rt->create_avlnode(key);
        }

        if (rt->key > key) {
            rt->left = inserthelp(rt->left, key);
        }
        
        else {
            rt->right = inserthelp(rt->right, key);
        }
        
        rt->height = 1 + max(height(rt->left), height(rt->right));
        rt->nodec = 1 + leftnodecount(rt) + rightnodecount(rt);
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
    };

    int findhelp(AVLNode *root, int key, int idx) {
        if (root == NULL) {
            return 0;
        }
        
        if (key > root->key) {
            idx += leftnodecount(root) + 1;
            return findhelp(root->right, key, idx);
        }

        else if (key == root->key) {
            return leftnodecount(root) + idx;
        }

        else {
            return findhelp(root->left, key, idx);
        }
    };

public:
    AVLNode *root;
    int nodecount;

    AVL() {
        root = NULL;
        nodecount = 0;
    };

    ~AVL() {
        delete root;
        nodecount = 0;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    };

    void find(AVLNode *root, int key) {
        int temp = findhelp(root, key, 1);

        if (temp == 0) {
            cout << "Data tidak ada" << '\n';
            return;
        }
        
        cout << temp << '\n';
    };
};

int main() {
    AVL tree;

    int cases;
    int command[2];

    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> command[0] >> command[1];

        if (command[0] == 1) {
            tree.insert(command[1]);
        }

        else if (command[0] == 2) {
            tree.find(tree.root, command[1]);
        }
    }

    return 0;
}