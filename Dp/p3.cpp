#include <bits/stdc++.h>
using namespace std;

int houserobberrecursion(int index,vector<int>& nums){
    if(index==0)return nums[index];
    if(index<0)return 0;
    int pick=nums[index]+houserobberrecursion(index-2,nums);
    int notpick=0+houserobberrecursion(index-1,nums);
    return max(pick,notpick);
}
int memohouserobber(int index,vector<int>& nums,vector<int>& dp){
 if(index==0)return nums[index];
    if(index<0)return 0;
    if(dp[index]!=-1)return dp[index];
    int pick=nums[index]+memohouserobber(index-2,nums,dp);
    int notpick=0+memohouserobber(index-1,nums,dp);
    return dp[index]=max(pick,notpick);
}
int main() {
 
    vector<int>nums={1,2,3,1};
    vector<int>dp1(nums.size(),-1);
    vector<int>dp(nums.size(),-1);
    dp[0]=nums[0];
    // cout<< houserobberrecursion(nums.size()-1,nums)<<endl;
    // cout<<memohouserobber(nums.size()-1,nums,dp1);
    for(int i=1;i<nums.size();i++){
        int take=nums[i];
        if(i>1)take+=dp[i-2];
        int nottake=dp[i-1];

        dp[i]=max(take,nottake);

    }
    cout<< dp[nums.size()-1];


    



    
    
    return 0;
}