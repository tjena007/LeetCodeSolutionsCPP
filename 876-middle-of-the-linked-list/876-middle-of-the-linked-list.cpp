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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* temp = head;
        int total = 0;
        while(temp!=NULL){
            temp = temp->next;
            total++;
        }
        //cout << total;
        
        temp = head;
        int mid = total/2;
        int count = 0;
        while(temp!=NULL){
            count++;
            if(count == mid){
                return temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};