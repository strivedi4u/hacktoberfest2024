class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* temp = head;
        unordered_set<ListNode*> p;

        while(temp != nullptr){
            
            if(p.find(temp) != p.end()){
                return true;
            }
            
            p.insert(temp);
            temp = temp -> next;
        }

        return false;
    }
};
