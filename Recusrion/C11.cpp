#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(string &s, int index) {
        if (index == s.size()) {
            cout << s << "\n";
            return;
        }

        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);              // Choose
            permute(s, index + 1);             // Explore
            swap(s[index], s[i]);              // Un-choose (backtrack)
        }
    }
};

int main() {
    string s = "ABC";
    Solution sol;
    sol.permute(s, 0);
    return 0;
}
