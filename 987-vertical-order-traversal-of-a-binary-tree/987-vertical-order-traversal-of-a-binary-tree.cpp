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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0;i<size;i++){
                auto p = todo.front();
                todo.pop();
                int x = p.second.first,y = p.second.second;
                
                TreeNode* node = p.first;
                nodes[x][y].insert(node->val);   
                if(node->left != NULL){
                    todo.push({node->left,{x-1,y+1}});
                }
                if(node->right != NULL){
                    todo.push({node->right,{x+1,y+1}});
                }
            }
        }
        
        for(auto p: nodes){
            vector<int> col;
            for(auto m: p.second){
                col.insert(col.end(),m.second.begin(),m.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};