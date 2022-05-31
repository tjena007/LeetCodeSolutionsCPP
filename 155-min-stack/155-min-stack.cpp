class MinStack {
public:
    vector<int> nums;
    vector<int> minnums;
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push_back(val);
        int minval = minnums.size()>0 ? min(val,minnums[minnums.size()-1]) : val;
        minnums.push_back(minval);
    }
    
    void pop() {
        nums.pop_back();
        minnums.pop_back();
    }
    
    int top() {
        int end = nums.size()-1;
        return nums[end];
    }
    
    int getMin() {
        return minnums[minnums.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */