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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int total = 0;
        
        while(temp!=NULL){
            total++;
            temp = temp->next;
        }
        
        temp = head;
        int node = total-n;
        if(node == 0){
            if(head->next != NULL){
                head= head->next;
                return head;
            }
            else{
                return NULL;    
            }
        }
        
        int count = 0;
        
        while(temp!=NULL){
            count++;
            if(count == node){
                if(temp->next->next != NULL){
                temp->next = temp->next->next;
                }
                else{
                    temp->next = NULL;
                }
            }
            temp = temp->next;
        }
        
        return head;
    }
};