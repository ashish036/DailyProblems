// https://practice.geeksforgeeks.org/problems/5877fde1c8e1029658845cd4bc94066ac1d4b09b/1
#include <bits/stdc++.h>
#include <math.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    int findleftPosition(int num, vector<int> &temp) { // Big or same 
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            int mid = (i+j)/2;
            if (temp[mid] < num) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return j;
    }
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n), sum(n);
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = arr[i];
        }
        sort(temp.begin(),temp.end());
        sum[0] = temp[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1]+temp[i];
        }
        for(int i = 0; i < n; i++) {
            int pos = findleftPosition(arr[i],temp);
            if (pos == 0){
                ans[i] = 0;
            } else {
                ans[i] = sum[pos-1];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends