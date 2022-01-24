/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>&nums){
        if(root == NULL){
            return;
        }
        helper(root->left,nums);
        nums.push_back(root->val);
        helper(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        helper(root,nums);
        
        int low=0,high = nums.size()-1;
        while(low<high){
            if(nums[low] + nums[high] == k){
                return true;
            }
            else if(nums[low] + nums[high] > k){
                high--;
            }
            else{
                low++;
            }
        }
        
        return false;
    }
};