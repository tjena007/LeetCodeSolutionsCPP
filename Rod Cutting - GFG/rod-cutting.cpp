//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int unboundedKS(int* price,vector<int>& wt,int n){
        vector<vector<int>> mat(n+1,vector<int>(n+1));
        
        //intialization with 0 and 0 for i and  j
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0)mat[i][j] = 0;
                
                if(j == 0)mat[i][j] = 0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(wt[i-1] > j){
                    mat[i][j] = mat[i-1][j];
                }
                else{
                    mat[i][j] = max(mat[i-1][j], price[i-1] + mat[i][j - wt[i-1]]);
                }
            }
        }
        
        return mat[n][n];
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<int> wt;
        for(int i=1;i<=n;i++){
            wt.push_back(i);
        }
        
        return unboundedKS(price,wt,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends