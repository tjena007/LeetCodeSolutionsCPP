class Solution {
public:
    void function(vector<char>& s, int start, int end){
        if(start >= end) return;
        swap(s[start],s[end]);
        function(s,start+1,end-1);
    }
    void reverseString(vector<char>& s) {
        function(s,0,s.size()-1);
    }
};