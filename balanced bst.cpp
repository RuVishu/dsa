#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class BalancedTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int value) {
        if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

public:
    BalancedTree() : root(NULL) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BalancedTree tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);

    cout << "In-order Traversal: ";
    tree.displayInorder();

    return 0;
}
