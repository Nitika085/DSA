#include <bits/stdc++.h>
using namespace std;

int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maximum=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[day][i]+f(day-1,i,points,dp);
            maximum=max(maximum,point);
        }
    }
    return dp[day][last]=maximum;
}

int main() {
   
    vector<vector<int>>points={
        {2,1,3},
        {3,4,6},
        {10,1,6},
        {8,3,7}

    };
    int n=points.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<f(points.size()-1,3,points,dp);

    
    
    return 0;
}