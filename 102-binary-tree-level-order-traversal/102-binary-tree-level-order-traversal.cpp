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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> st;
        st.push(root);
        while(st.size()!=0){
            int size = st.size();
            vector<int> row;
            for(int i=0;i<size;i++){
                auto node = st.front();
                st.pop();
                row.push_back(node->val);
                if(node->left != NULL)st.push(node->left);
                if(node->right != NULL)st.push(node->right);
            }
            ans.push_back(row);
        }
        
        
        return ans;
    }
};