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
        ListNode dummy(0); // Create a dummy node
        ListNode* current = &dummy; // Pointer to build the new list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1; // Attach list1 node
                list1 = list1->next;
            } else {
                current->next = list2; // Attach list2 node
                list2 = list2->next;
            }
            current = current->next; // Move current to the next position
        }

        // Attach remaining nodes
        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next; // Return the head of the merged list
    }
};

// Function to create a linked list from user input
ListNode* createList() {
    int n;
    cout << "Enter number of nodes in the list: ";
    cin >> n;

    if (n <= 0) return nullptr; // Return null for empty lists

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
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
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << std::endl;
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

    return 0;
}
