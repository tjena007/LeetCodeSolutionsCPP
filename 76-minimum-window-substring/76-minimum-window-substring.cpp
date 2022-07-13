class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int al = INT_MAX;
        int i=0,j=0;
        map<char,int> mt;
        map<char,int> ms;
        for(auto i: t){
            mt[i]++;
        }
        int have=0,need=mt.size();
        while(j<s.size()){
            if(mt.find(s[j]) != mt.end()){
                ms[s[j]]++;
                if(ms[s[j]] == mt[s[j]]) have++;
                                                   
                while(have == need){
                    int len = j-i+1;
                    if(len < al){
                        al = len;
                        ans = s.substr(i, (len));
                    }
                    //cout << s[i] << endl;
                    if(mt.find(s[i]) != mt.end() && --ms[s[i]] < mt[s[i]]){
                        //ms[s[i]]--;
                        have--;
                    }
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};