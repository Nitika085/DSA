#include <bits/stdc++.h>
using namespace std;


//fibonacci series
int f(vector<int>& dp,int n){
if(n<=1)return n;
if(dp[n]!=-1)return dp[n];
return dp[n]=f(dp,n-1)+f(dp,n-2);

}

int main() {
    int n;
    cout<<"Enter the values of n"<<endl;
    cin>>n;
   vector<int>dp(n+1,-1);
   cout<<f(dp,n);


    
    
    return 0;
}