#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Merges two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(); // Placeholder node
        ListNode *ptr = dummy; // Pointer to build merged list
        
        // Compare nodes from both lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1; // Add smaller node
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        
        // Append remaining nodes
        ptr->next = list1 ? list1 : list2;
        
        return dummy->next; // Return merged list (skip dummy)
    }
};
