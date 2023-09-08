class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s = calc(n);
        
        return s[k-1];
    }
    
    string calc(int n){
        if(n==1){
            return "0";
        }
        string prev = calc(n-1);
        
        // cout << prev << endl;
        
        string r= invert(prev);
        reverse(r.begin(),r.end());
        // cout << r << endl;
        
        string newstr = prev + "1" + r;
        
//         cout << newstr << endl;
        
//         cout << "----------------------------" << endl;
        
        return newstr;
    }
    
    string invert(string str){
        for(int i=0;i<str.size();i++){
            if(str[i] == '0'){
                str[i] = '1';
            }
            else{
                str[i] = '0';
            }
        }
        
        return str;
    }
};