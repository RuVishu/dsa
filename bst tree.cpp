#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL)
            return NULL;
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    Node* search(Node* node, int value) {
        if (node == NULL || node->data == value)
            return node;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

    void preorder(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node* node) {
        if (node == NULL)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void levelOrderTraversal(Node* node) {
        if (node == NULL)
            return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void searchAndReplace(int oldValue, int newValue) {
        Node* target = search(root, oldValue);
        if (target != NULL) {
            deleteNode(oldValue);
            insert(newValue);
            cout << "Replaced " << oldValue << " with " << newValue << " and adjusted position." << endl;
        } else {
            cout << oldValue << " not found in the BST." << endl;
        }
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }

    void displayLevelOrder() {
        levelOrderTraversal(root);
        cout << endl;
    }

    int getHeight() {
        return height(root);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.displayInorder();

    cout << "Pre-order Traversal: ";
    tree.displayPreorder();

    cout << "Post-order Traversal: ";
    tree.displayPostorder();

    cout << "Level-order Traversal: ";
    tree.displayLevelOrder();

    cout << "Height of the tree: " << tree.getHeight() << endl;

    tree.deleteNode(50);
    cout << "In-order Traversal after deleting 50: ";
    tree.displayInorder();

    tree.searchAndReplace(40, 45);
    cout << "In-order Traversal after replacing 40 with 45: ";
    tree.displayInorder();

    return 0;
}
