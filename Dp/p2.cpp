//frogjumps
#include <bits/stdc++.h>
using namespace std;
// int frogjumps(vector<int>&dp,int n,vector<int>& jumps){
// if(n==0)return 0;
// if(dp[n]!=-1)return dp[n];
// int l=frogjumps(dp,n-1,jumps)+abs(jumps[n]-jumps[n-1]);
// int r=INT_MAX;
// if(n>1)r=frogjumps(dp,n-2,jumps)+abs(jumps[n]-jumps[n-2]);
   
// return dp[n]=min(l,r);

// }
int main() {
  
    vector<int>jumps={30,10,60,10,60,50};
    int n=jumps.size();
    // vector<int>dp(n,0);
    // // cout<< frogjumps(dp,n-1,jumps);
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int left=dp[i-1]+abs(jumps[i]-jumps[i-1]);

    //     int right=dp[i-2]+abs(jumps[i]-jumps[i-2]);

    //     dp[i]=min(left,right);
    // }

    int prev2=0;
    int prev=0;
    for(int i=1;i<n;i++){
 int left=prev+abs(jumps[i]-jumps[i-1]);

        int right=prev2+abs(jumps[i]-jumps[i-2]);
        int curri=min(left,right);
        prev2=prev;
        prev=curri;


    }
cout<< prev;
    
    return 0;
}