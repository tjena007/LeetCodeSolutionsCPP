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
    ListNode* removeElements(ListNode* head, int val) {
        if(head== NULL){
            return NULL;
        }
        ListNode* temp =head;
        while(temp->next!=NULL){
            if(head->val == val){
                if(head->next != NULL){
                    head=head->next;    
                }
                else{
                    return NULL;    
                }
            }
            else if(temp->next->val == val){
                temp->next = temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        if(head->val == val){
            return NULL;
        }
        
        return head;
    }
};