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
        int count=0;
        
        auto temp = head;
        
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        
        temp = head;
        
        int toDelete = count - n;
        if(toDelete == 0){
            if(count == 1)return NULL;
            else{
                head= head->next;
                return head;
            }
        }
        
        int c= 1;
        while(c != toDelete){
           c++; 
           temp = temp->next; 
        }
        
        if(temp->next->next != NULL){
            temp->next = temp->next->next; 
        }
        else{
            temp->next = NULL;
        }
        
        return head;
    }
};