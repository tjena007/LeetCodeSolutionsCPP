class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        
        for(int i=0;i<board.size();i++){ //row wise check
            map<int,int> m;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>='1' && board[i][j]<='9'){
                    int num = board[i][j]-'0';
                    m[num]++;    
                }                
            }
            for(auto i : m){
                //cout << i.first << " " << i.second << endl;
                if(i.second > 1){
                    cout << "row";
                    return false;
                }
            }
        }
        
        for(int i=0;i<9;i++){ //col wise check
            map<int,int> m;
            for(int j=0;j<9;j++){
                if(board[j][i] >='1' && board[j][i] <='9'){
                    int num = board[j][i]-'0';
                    m[num]++;    
                }
            }
            for(auto i : m){
                //cout << i.first << " " << i.second << endl;
                if(i.second > 1){
                    cout << "column";
                    return false;
                }
            }
            //cout << " next col" << endl;
        }
        
        int rc=0,cc=0;
        
        while(rc<9){
            //cout << "hi" << endl;
            map<int,int> m;
            for(int i=rc;i<rc+3;i++){
                for(int j=cc;j<cc+3;j++){
                    //cout << board[i][j];
                    if(board[j][i] >='1' && board[j][i] <='9'){
                        int num = board[j][i]-'0';
                        m[num]++;    
                    }
                }
            }
            
            for(auto i : m){
                //cout << i.first << " " << i.second << endl;
                if(i.second > 1){
                    //cout << "sqaure";
                    return false;
                }
            }
            
            cc+=3;
            if(cc==9){
                rc+=3;
                cc=0;
            }
        }
        
        
        
        return ans;
    }
};