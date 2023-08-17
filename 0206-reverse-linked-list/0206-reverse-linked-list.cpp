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
    ListNode* start = NULL;
    ListNode* reverseList(ListNode* head) {
       reverse(head);
       return start; 
    }

    ListNode* reverse(ListNode* curr){
        if(curr== NULL || curr->next == NULL){
            start = curr;
            return curr;
        }
        
        auto node = reverse(curr->next);
        node->next = curr;
        curr->next = NULL;
        
        return node->next;
    }
};