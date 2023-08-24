//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        // cout << arr.size() << endl;
        vector<int> ans;
        
        calc(0,0,arr,ans,N);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void calc(int idx,int sum,vector<int>& arr,vector<int>& ans,int N){
        if(idx == N){
            ans.push_back(sum);
            return;
        }
        
        calc(idx+1,sum+arr[idx],arr,ans,N);
        
        calc(idx+1,sum,arr,ans,N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends