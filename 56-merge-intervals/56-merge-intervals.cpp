class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int k=0;
        for(int j=1;j<intervals.size();j++){
            if(intervals[j][0]<=ans[k][1]){
                ans[k][1] = max(ans[k][1],intervals[j][1]);
            }
            else{
                ans.push_back(intervals[j]);
                k++;
            }
        }
        
        return ans;
    }
};