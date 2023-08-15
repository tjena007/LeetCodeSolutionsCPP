class Solution {
public:
    int compress(vector<char>& chars) {
        int count =0;
        
        int i=0;
        while(i<chars.size()){
            if(count == 0){
                // cout << chars[i] << " curr ";
                int init = i+1;
                count++;
                i++;
                while(i<chars.size() && chars[i] == chars[i-1]){
                    count++;
                    i++;
                }
                // cout << count << endl;
                // cout << init << " " << i << endl;
                if(i == init || count == 1){
                    count =0;
                    continue;
                }
                else{
                    string num = to_string(count);
                    // cout << 
                    for(int j=0;j<num.size();j++){
                        chars.insert(chars.begin()+init,num[j]);
                        init++;
                        i++;
                    }
                    if(i == chars.size()){
                        chars.erase(chars.begin() + init,chars.end()); 
                    }
                    else{
                        // cout << "here" << init << " " << i << endl; 
                        chars.erase(chars.begin() + init, chars.begin()+i);
                    }
                    // for(auto k : chars){
                    //     cout << k << " " ; 
                    // }
                    // cout << "curr idx " << i <<endl;
                    i = init;
                    count = 0;
                }    
            }        
        }
        
        return chars.size();
    }
};