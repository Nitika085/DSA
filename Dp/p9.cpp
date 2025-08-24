#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // right - left gives window size after deleting one 0
            res = max(res, right - left);
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,0,1,1,1,0,1,1};
    cout << "Longest subarray after deleting one element: " 
         << sol.longestSubarray(nums) << endl;

    return 0;
}
