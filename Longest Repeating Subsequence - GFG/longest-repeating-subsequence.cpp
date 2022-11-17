//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s2 = str;
		    int m = str.size();
            int n = str.size();
    
            vector<vector<int>> mat(m+1,vector<int>(n+1));
            for(int i=0;i<m+1;i++){
                for(int j=0;j<n+1;j++){
                    if(i==0 || j==0){
                        mat[i][j] = 0;
                    }
                }
            }
    
            for(int i=1;i<m+1;i++){
                for(int j=1;j<n+1;j++){
                    if(str[i-1] == s2[j-1] && i!=j){
                        mat[i][j] = 1 + mat[i-1][j-1];
                    }
                    else{
                        mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
                    }
                }
            }
            
            return mat[m][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends