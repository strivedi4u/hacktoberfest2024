/**********************************************
Floyd's Cycle Finding Algorithm
    Uses only two pointers, which move at different speeds.
    Often called the "Tortoise and the Hare Algorithm"

    Algorithm is named after Robert W. Floyd.

    https://en.wikipedia.org/wiki/Cycle_detection

***********************************************/
#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head) return false;

    ListNode* tortoise = head; //slow ptr
    ListNode* hare = head;     //fast ptr

    while (hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;  //move tortoise by 1 step
        hare = hare->next->next;    //move hare by two steps

        if(tortoise == hare) {      //cycle detected
            return true;
        }
    }
    return false;                   //no cycle

}


//example of use
int main() {
    //linked list: 1->2->3->4->5->nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    //adding cycle from 5->3
    head->next->next->next->next->next = head->next->next;

    //check for cycle
    if(hasCycle(head)) {
        std::cout << "Cycle Detected!" << std::endl;
    }
    else{
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}
