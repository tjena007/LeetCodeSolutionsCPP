class Solution {
public:
    bool dfs(vector<int>& arr, int start,vector<int> &vis){
        if(arr[start] == 0){
            return true;
        }
        vis[start] = 1;
        bool a=false,b=false;
        if(start - arr[start] >=0 && vis[start - arr[start]]==0){
            a = dfs(arr,start-arr[start],vis);
        }
        if(start + arr[start] <= arr.size()-1 && vis[start + arr[start]]==0){
            b = dfs(arr,start+arr[start],vis);    
        }
        
        return a||b;
    
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return dfs(arr,start,vis);
    }
};