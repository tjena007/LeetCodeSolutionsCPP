/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
    
    ListNode* swap(ListNode* head){
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        //swap head,
        auto t = head->next;
        head->next = swap(head->next->next);
        t->next = head;
        
        
        // swap(t->next->next);
        return  t;
    }
};