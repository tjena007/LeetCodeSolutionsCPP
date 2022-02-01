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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* temp = head;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        bool carry = false;
        
        while(temp1!= NULL && temp2!= NULL){
            int sum = temp1->val + temp2->val;
            if(carry){
                sum++;
            }
            if(sum>=10){
                sum = sum%10;
                carry = true;
            }
            else{
                carry = false;
            }
            
            ListNode* node = new ListNode(sum);
            node->next = NULL;
            // node->val = sum;
            if(head == NULL){
                head = node;
                temp = head;
            }
            else{
                temp->next = node;
                temp = temp->next;
            } 
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1 != NULL){
            int sum = temp1->val;
            if(carry){
                sum++;
            }
            if(sum>=10){
                sum = sum%10;
                carry = true;
            }
            else{
                carry = false;
            }
            
            ListNode* node = new ListNode(sum);
            node->next = NULL;
            
            temp->next = node;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int sum = temp2->val;
            if(carry){
                sum++;
            }
            if(sum>=10){
                sum = sum%10;
                carry = true;
            }
            else{
                carry = false;
            }
            
            ListNode* node = new ListNode(sum);
            node->next = NULL;
            
            temp->next = node;
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            node->next = NULL;
            
            temp->next = node;
            temp = temp->next;
        }
        
        
        return head;
        
    }
};