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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dumm = new ListNode(-1);
        ListNode* tail = dumm;
        
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                tail->next = head1;
                head1 = head1->next;
            }
            else{
                tail->next = head2;
                head2 = head2->next;
            }
            
            tail = tail->next;
        }
        
        if(head1 != NULL){
            tail->next = head1;
        }
        if(head2 != NULL){
            tail->next = head2;
        }
        
        return dumm->next;
    }
};