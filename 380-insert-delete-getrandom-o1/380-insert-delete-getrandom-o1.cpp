class RandomizedSet {
public:
    map<int,int> m;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it = m.find(val);
        if(it != m.end()){
            return false;
        }
        else{
            nums.push_back(val);
            m[val] = nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        //cout << m[val];
        auto it = m.find(val);
        if(it != m.end()){
            int index = m[val];
            int val2 = nums[nums.size()-1];
            m[val2] = index;
            swap(nums[index],nums[nums.size()-1]);
            nums.pop_back();
            m.erase(val);
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int getRandom() {
        
        int v1 = rand() % nums.size();
        return nums[v1];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */