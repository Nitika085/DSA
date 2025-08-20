#include <bits/stdc++.h>
using namespace std;

// Count subsets that sum to target
int check(vector<int>& arr, int index, int target, vector<vector<int>>& dp) {
   if(index==0){
        if (target == 0) return 1;
        return arr[0] == target;
        }
        if(target==0)return 1;
    if (dp[index][target] != -1) return dp[index][target];

    int notake = check(arr, index - 1, target, dp);
    int take = 0;
    if (arr[index] <= target)
        take = check(arr, index - 1, target - arr[index], dp);

    return dp[index][target] = take + notake;
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    int total = accumulate(arr.begin(), arr.end(), 0);

    // Subset sum formulation:
    // sum(S1) - sum(S2) = diff
    // sum(S1) = (diff + total) / 2
    if ((diff + total) % 2 != 0) {
        cout << 0;
        return 0;
    }
    int target = (diff + total) / 2;

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    int ans = check(arr, n-1, target, dp);

    cout << ans;
    return 0;
}
