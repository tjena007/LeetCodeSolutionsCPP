class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        map<int,int> m;
        
        for(auto i : nums){
            m[i]++;
        }
        
        vector<int> n;
        
        for(auto i : m){
            n.push_back(i.first);
        }
        
        int i=0,j=0;
        
        int ans=1;
        int count = 1;
        
        while(j<n.size()){
            j++;
            if(j<n.size()){
                if(n[j]-n[j-1] == 1){
                count++;
                }
                else{
                    ans = max(ans,count);
                    count=1;
                    i=j;
                }    
            }
            
            ans = max(ans,count);
            
        }
        
        return ans;
    }
};