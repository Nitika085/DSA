#include <bits/stdc++.h>
using namespace std;
 int check(vector<int>&arr,int index, int& target, vector<vector<int>>& dp){
        if(index==0){
        if (target == 0) return 1;
        return arr[0] == target;
        }
        if(target==0)return 1;
        if(dp[index][target]!=-1)return dp[index][target];

        int notake=check(arr,index-1,target,dp);
        int take=0;
        if(target>=arr[index]){
            int nextarget=target-arr[index];
            take=check(arr,index-1,nextarget,dp);
        }
        return dp[index][target]=take+notake;

    }
int main() {

    
    	vector<int>arr={  1,1,1,1};
    
     int total=0;
     for(int x:arr){
        total+=x;
     }
     int target=total/2;
        int ans=0;
        int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
   check(arr,n-1,target,dp);
        cout<<dp[n-1][target]/2;
    
    return 0;
}