//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string str, int n) { 
    //complete the function here 
    string s2 = str;
    reverse(s2.begin(),s2.end());
    
    int m = str.size();
    
    vector<vector<int>> mat(m+1,vector<int>(m+1));
    
    for(int i=0;i<m+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                mat[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<m+1;i++){
        for(int j=0;j<m+1;j++){
            if(str[i-1] == s2[j-1]){
                mat[i][j] = 1 + mat[i-1][j-1];
            }
            else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    
    int lcs = mat[m][m];
    
    return m-lcs;
} 