class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int ans = 0;
        for(auto i : nums){
            m[i]++;
        }
        
        for(auto i : nums){
            if(m.find(k-i) != m.end() && m.find(i) != m.end()){
               if(k-i == i && m[i]<2) continue;
               ans++; 
               m[i]--;
               if(m[i] == 0) m.erase(i);
               m[k-i]--;
                if(m[k-i] == 0) m.erase(k-i);
            }
            // for(auto i : m){
            //     cout << i.first << " " << i.second << endl;
            // }
            // cout << "-----------------" << endl;
        }
        
        return ans;
    }
};