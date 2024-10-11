// C++ Program to add two number represented as
// linked list by creating a new list
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// function to reverse the linked list
Node *reverse(Node *head) {
    Node *prev = nullptr, *curr = head, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add two numbers represented by linked list
Node *addTwoLists(Node *num1, Node *num2) {
    Node *res = nullptr, *curr = nullptr;
    int carry = 0;

    num1 = reverse(num1);
    num2 = reverse(num2);

    // Iterate till either num1 is not empty or num2 is
    // not empty or carry is greater than 0
    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = carry;

        // If num1 linked list is not empty, add it to sum
        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        // If num2 linked list is not empty, add it to sum
        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }
      
          // Create a new node with sum % 10 as its value
        Node* newNode = new Node(sum % 10);

        // Store the carry for the next nodes
        carry = sum / 10;

          // If this is the first node, then make this node
          // as the head of the resultant linked list
          if(res == nullptr) {
            res = newNode;
              curr = newNode;
        }
          else {
              
              // Append new node to resultant linked list
              // and move to the next node
            curr->next = newNode;
            curr = curr->next;
        }
    }

    // Reverse the resultant linked list to get the
    // required linked list
    return reverse(res);
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {

    // Creating first linked list: 1 -> 2 -> 3
    // (represents 123)
    Node *num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    // Creating second linked list: 9 -> 9 -> 9
    // (represents 999)
    Node *num2 = new Node(9);
    num2->next = new Node(9);
    num2->next->next = new Node(9);

    Node *sum = addTwoLists(num1, num2);
    printList(sum);

    return 0;
}
