class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(auto i : stones){
           maxh.push(i); 
        }
        
        while(maxh.size()>1){
            int high = maxh.top();
            maxh.pop();
            int sec = maxh.top();
            maxh.pop();
            if(high == sec) continue;
            else{
                maxh.push(abs(high-sec));
            }
        }
        if(maxh.size() == 0) return 0;
        return maxh.top();
    }
};