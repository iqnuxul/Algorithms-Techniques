#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void Print() {
        inOrderTraversal(root);
        cout << endl;
    }

    void Add(int value) {
        root = insertNode(root, value);
    }

    Node* Find(int value) {
        return search(value, root);
    }

    void Delete(int value) {
        root = deleteNode(root, value);
    }

private:
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }


    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }



    Node* search(int value, Node* node) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return search(value, node->left);
        } else {
            return search(value, node->right);
        }
    }




    Node* findTheSuccessor(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int value) {
        // empty tree
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } 
        else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } 
        else {

            // 0 child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // 1 child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // 2 children
            Node* successor = findTheSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }

        return root;
    }


};

int main() {
    BST tree;

    tree.Add(3);
    tree.Add(7);
    tree.Add(5);
    tree.Add(4);
    tree.Add(8);
    tree.Add(6);
    tree.Add(2);

    cout << "BST: ";
    tree.Print();

    int valueToFind = 4;
    Node* foundNode = tree.Find(valueToFind);
    if (foundNode != nullptr) {
        cout << "Find " << valueToFind << ": Found" << endl;
    } else {
        cout << "Find " << valueToFind << ": Not found" << endl;
    }

    int valueToDelete = 3;
    cout << "Delete " << valueToDelete << endl;
    tree.Delete(valueToDelete);
    tree.Print();

    return 0;
}
