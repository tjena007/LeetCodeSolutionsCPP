class Solution {
public:
    string reverseVowels(string s) {
        vector<int> idx;
        vector<char> vowels;
        
        
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
|| s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U'){
               idx.push_back(i);
               vowels.push_back(s[i]);
            }
        }
        
//         for(auto i : idx){
//             cout << i << " ";
//         }
//         cout << endl;
        
//         for(auto i : vowels){
//             cout << i << " ";
//         }
//         cout << endl;
        
        
        reverse(vowels.begin(),vowels.end());
        
        for(int i=0;i<idx.size();i++){
            s[idx[i]] = vowels[i];
        }
        
        return s;
    }
};