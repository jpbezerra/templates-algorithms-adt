#include <iostream>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode *create_avlnode(int key) {
        AVLNode *node = new AVLNode;
        node->key = key;
        node->height = 0;
        node->left = node->right = NULL;

        return node;
    };
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
        
        return (height(rt->key) - height(rt->right));
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
            return rt->create_avlnode(key);
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
    };

    int *findhelp(AVLNode *root, int key) {
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

    AVLNode *getmin(AVLNode *root) {
        if (root->left == NULL) {
            return root;
        }
        
        return getmin(root->left);
    };

    AVLNode *deletemin(AVLNode *root) {
        if (root->left == NULL) {
            return root->right;
        }
        
        root->left = deletemin(root->left);

        return root;
    };

    AVLNode *removehelp(AVLNode *root, int key) {
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
                AVLNode *temp = getmin(root->right);
                root->key = temp->key;
                root->right = deletemin(root->right);
            }
        }

        return root;
    }

public:
    AVL() {
        root = NULL;
        nodecount = 0;
    };

    ~AVL() {
        delete root;
        nodecount = 0;
        cout << "Destroyed\n";
    };

    AVLNode *getroot() {
        return root;
    };

    int getnodecount() {
        return nodecount;
    };

    void insert(int key) {
        root = inserthelp(root, key);
        nodecount++;
    };

    void find(AVLNode *root, int key) {
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

    void preorder(AVLNode *rt) {
        if (rt != NULL) {
            cout << " " << rt->key;

            preorder(rt->left);
            preorder(rt->right);
        }
    };

    void inorder(AVLNode *rt) {
        if (rt != NULL) {

            inorder(rt->left);
            cout << " " << rt->key;
            inorder(rt->right);
        }
    };

    void postorder(AVLNode *rt) {
        if (rt != NULL) {
            postorder(rt->left);
            postorder(rt->right);
            cout << " " << rt->key;
        }
    };
};

int main() {
    AVL tree;

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