class Solution {
public:
    void find(int ind,int target,vector<int>& candidates,   vector<vector<int>>&v, vector<int>&n){
      if(ind==candidates.size()){
          if(target==0){
              v.push_back(n);
          }
          return;
      }
      if(candidates[ind]<=target){
          n.push_back(candidates[ind]);
          find(ind,target-candidates[ind],candidates,v,n);
          n.pop_back();
      }
       find(ind+1,target,candidates,v,n);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>n;
        find(0,target,candidates,v,n);
return v;
    }
};