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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>,greater<int>> minh;
        
        for(auto i : lists){
            ListNode* head = i;
            while(head != NULL){
                minh.push(head->val);
                head = head->next;
            }
        }
        
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(!minh.empty()){
            int val = minh.top();
            ListNode* node = new ListNode(val);
            if(head!=NULL){
                temp->next = node;    
                temp = temp->next;
            }
            else{
                head = node;
                temp = head;
            }
            minh.pop();
        }
        return head;
    }
};