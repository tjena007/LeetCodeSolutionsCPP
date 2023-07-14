class Solution {
public:
    set<vector<int>> st;

    void findCombinations(vector<int>& candidates,vector<int> curr,int target){
        if(target == 0){
            sort(curr.begin(),curr.end());
            st.insert(curr);
            return;
        }
        // if(target < candidates[0]) return;

        for(int i=0;i<candidates.size();i++){
            int diff = target - candidates[i];
            if(diff < 0) continue;
            else{
                vector<int> temp = curr;
                temp.push_back(candidates[i]);
                findCombinations(candidates,temp,diff);
            }   
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        findCombinations(candidates,{},target);        

        for(auto it: st){
            ans.push_back(it);
        }

        return ans;
        
        
    }
};