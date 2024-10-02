#include <bits/stdc++.h>
using namespace std;

// Structure to represent a node in the binary tree
struct Node {
    int key;
    Node *left, *right;
    // Constructor to initialize node with a value
    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the height (depth) of the binary tree
int height(Node* root) {
    if (!root) return 0;  // If the tree is empty, height is 0

    // Initializing a queue to traverse the tree level by level
    queue<Node*> q;
    q.push(root);  // Start from the root node
    int h = 0;     // Variable to store the height of the tree

    // Loop until the queue is empty
    while (!q.empty()) {
        int size = q.size();  // Get the number of nodes at the current level

        // Traverse all nodes at the current level
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();  // Get the front node
            q.pop();                 // Remove the node from the queue
            
            // If the left child exists, add it to the queue
            if (temp->left) q.push(temp->left);
            // If the right child exists, add it to the queue
            if (temp->right) q.push(temp->right);
        }

        // Increment height after processing each level
        h++;
    }
    return h;  // Return the calculated height
}

// Function to create a binary tree from user input
Node* createTree() {
    int val;
    cout << "Enter root node value: ";
    cin >> val;
    
    if (val == -1) return nullptr;  // If the user enters -1, the tree is empty
    
    Node* root = new Node(val);  // Create the root node
    queue<Node*> q;
    q.push(root);
    
    // Loop to add nodes to the tree level by level
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        int leftVal, rightVal;
        cout << "Enter left child of " << curr->key << " (-1 if no left child): ";
        cin >> leftVal;
        
        // If the left child value is not -1, create the left child node
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
        
        cout << "Enter right child of " << curr->key << " (-1 if no right child): ";
        cin >> rightVal;
        
        // If the right child value is not -1, create the right child node
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;  // Return the created tree
}

int main() {
    // Create the binary tree from user input
    Node* root = createTree();
    
    // Find and print the height of the tree
    cout << "Height of the tree is: " << height(root) << endl;
    return 0;
}
