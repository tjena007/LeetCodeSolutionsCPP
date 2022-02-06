class Solution {
public:
    long long smallestNumber(long long num) {
        // vector<char>n = {'1','3','2'};
        // sort(n.begin(),n.end());
        // for(auto i: n) cout << i << " ";
        
        
        vector<int> nums;
        bool neg = false;
        if(num<0) neg = true;
        if(neg){
            num = abs(num);
        }
        while(num>0){
            int rem = num%10;
            nums.push_back(rem);
            num /= 10;
        }
        
        if(neg){
            sort(nums.begin(),nums.end(),greater<int>());
        }
        else{
            sort(nums.begin(),nums.end());
        
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    //cout << nums[i];
                    int digit = nums[i];
                    nums.erase(nums.begin()+i);
                    nums.insert(nums.begin(),digit);
                    break;
                }
            }
        }
        
        
        
        long long ans = 0;
        int j=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans+= nums[i]*pow(10,j);
            j++;
        }
        
        if(neg){
            ans *= -1;
        }
        
        // for(auto i: nums) cout << i << " ";
        
        return ans;
    }
};