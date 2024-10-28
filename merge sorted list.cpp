#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy(0); // Create a dummy node as a starting point
        ListNode* current = &dummy; // Pointer to build the merged list

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next; // Move to the next node in the merged list
        }

        // Attach remaining nodes from either list1 or list2
        current->next = list1 ? list1 : list2;

        return dummy.next; // Return the head of the merged list
    }
};

// Function to create a linked list from user input
ListNode* createList() {
    int n;
    cout << "Enter the number of nodes in the list: ";
    cin >> n;

    if (n <= 0) return nullptr; // Return null for an empty list

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter " << n << " values (in sorted order): ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to free memory of the linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    cout << "Creating first sorted linked list:\n";
    ListNode* list1 = createList();
    
    cout << "Creating second sorted linked list:\n";
    ListNode* list2 = createList();

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged sorted linked list:\n";
    printList(mergedList);

    // Free memory of all lists to prevent memory leaks
    deleteList(mergedList);

    return 0;
}
