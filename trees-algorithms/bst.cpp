#include <iostream>
#include <string>

/*
    Every time we type root->left or root->right or root->ket
    we can change to getleft(), getright() and getkey()

    If we want to use the root or the nodecount of the BST class we can
    do the same logic above
*/

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

    int getkey() {
        return key;
    };

    BSTNode *getleft() {
        return left;
    };

    BSTNode *getright() {
        return right;
    }
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

    int *findhelp(BSTNode *root, int key) {
        if (!root) {
            return NULL;
        }
        
        if (root->key > key) {
            return findhelp(root->left, key);
        }

        else if (root->key == key) {
            return &root->key;
        }

        else {
            return findhelp(root->right, key);
        }
    };

    BSTNode *getmin(BSTNode *root) {
        if (root->left == NULL) {
            return root;
        }
        
        return getmin(root->left);
    };

    BSTNode *deletemin(BSTNode *root) {
        if (root->left == NULL) {
            return root->right;
        }
        
        root->left = deletemin(root->left);

        return root;
    };

    BSTNode *removehelp(BSTNode *root, int key) {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->key > key) {
            root->left = removehelp(root->left, key);
        }
        
        else if (root->key < key) {
            root->right = removehelp(root->right, key);
        }
        
        else {
            if (root->left == NULL) {
                return root->right;
            }
            
            else if (root->right == NULL) {
                return root->left;
            }
            
            else {
                BSTNode *temp = getmin(root->right);
                root->key = temp->key;
                root->right = deletemin(root->right);
            }
        }

        return root;
    }

public:
    BST() {
        root = NULL;
        nodecount = 0;
    };

    ~BST() {
        delete root;
        nodecount = 0;
        cout << "Destroyed\n";
    };

    BSTNode *getroot() {
        return root;
    };

    int getnodecount() {
        return nodecount;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    };

    void find(BSTNode *root, int key) {
        int *temp =  findhelp(root, key);

        if (temp == NULL) {
            cout << "The element " << key << " wasn't found!" << endl;
            return;
        }
        
        cout << "The element " << key << " was found!" << endl;
    };

    void remove(int key) {
        int *temp = findhelp(root, key);

        if (temp != NULL) {
            root = removehelp(root, key);
            nodecount--;

            cout << "The element " << key << " was removed!" << endl;
            return;
        }

        cout << "The element " << key << " wasn't found, so the element wasn't removed" << endl;
        
        // return temp; // we can return the deleted element
    };

    void preorder(BSTNode *rt) {
        if (rt != NULL) {
            cout << " " << rt->key;

            preorder(rt->left);
            preorder(rt->right);
        }
    };

    void inorder(BSTNode *rt) {
        if (rt != NULL) {

            inorder(rt->left);
            cout << " " << rt->key;
            inorder(rt->right);
        }
    };

    void postorder(BSTNode *rt) {
        if (rt != NULL) {
            postorder(rt->left);
            postorder(rt->right);
            cout << " " << rt->key;
        }
    };
};


int main() {
    BST tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    tree.insert(7);
    tree.insert(12);
    tree.insert(9);
    tree.insert(14);
    tree.insert(23);
    tree.insert(21);
    tree.insert(18);
    tree.insert(56);

    tree.find(tree.getroot(), 5);
    tree.find(tree.getroot(), 123);
    tree.find(tree.getroot(), 56);

    cout << "Nodecount: " << tree.getnodecount() << endl;

    cout << "Pre order :";
    tree.preorder(tree.getroot());
    cout << endl;

    cout << "In order  :";
    tree.inorder(tree.getroot());
    cout << endl;

    cout << "Post order:";
    tree.postorder(tree.getroot());
    cout << endl;

    tree.remove(56);
    tree.remove(12);

    cout << "Nodecount: " << tree.getnodecount() << endl;

    cout << "Pre order :";
    tree.preorder(tree.getroot());
    cout << endl;

    cout << "In order  :";
    tree.inorder(tree.getroot());
    cout << endl;

    cout << "Post order:";
    tree.postorder(tree.getroot());
    cout << endl;

    return 0;
}