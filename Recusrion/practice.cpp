#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>fourSum(vector<int>& nums,int target){
vector<vector<int>>ans;
int n=nums.size();
sort(nums.begin(),nums.end());

for(int i=0;i<n-3;i++){
    if(i>0&& nums[i]==nums[i-1])continue;

    for(int j=i+1;j<n-2;j++){
        if(j>i+1&&nums[j]==nums[j-1])continue;
        int left=j+1;
        int right=n-1;

        while(left<right){
            long long sum=1LL*nums[i]+nums[j]+nums[left]+nums[right];

            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[left],nums[right]});

                while(left<right&&nums[left]==nums[left+1])left++;
                while(left<right&&nums[right]==nums[right-1])right--;

                left++;
                right--;

            }
        }
    }
}
return ans;
}

int main() {
    
    vector<int>nums={2,2,2,2,2,2};
    int target =8;
    vector<vector<int>>res=fourSum(nums,target);

    for(const auto& valid:res){
        for(int num:valid){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}