// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0;
        int sum =0;
        int ans = INT_MIN;
        while(i < N && j <N){
            sum+=Arr[j];
            if(j-i+1 < K){
                j++;
            }
            else{
               // cout << sum << endl;
                // sum+=Arr[j];
                ans = max(ans,sum);
                j++;
                // sum += Arr[j];
                sum -= Arr[i];
                i++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends