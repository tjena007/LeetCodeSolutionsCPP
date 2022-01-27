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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* temp = head;
        while(temp->next != NULL && head->next!=NULL){
            if(head->val == head->next->val){
                head = head->next;
            }
            else if(temp->val == temp->next->val && temp->next->next == NULL){
                temp->next = NULL;
            }
            else if(temp->val == temp->next->val && temp->next->next != NULL){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};