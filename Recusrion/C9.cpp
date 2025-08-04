#include <bits/stdc++.h>
using namespace std;

void solve(string s, string op, vector<string>& res) {
    if (s.length() == 0) {
        res.push_back(op);
        return;
    }

    if (isalpha(s[0])) {
        string op1 = op;
        string op2 = op;

        op1.push_back(tolower(s[0]));
        op2.push_back(toupper(s[0]));

        solve(s.substr(1), op1, res);
        solve(s.substr(1), op2, res);
    }
    else if (isdigit(s[0])) {
        string op1 = op;
        op1.push_back(s[0]);

        solve(s.substr(1), op1, res);
    }
}

vector<string> generates(string p) {
    vector<string> res;
    string op = "";
    solve(p, op, res);
    return res;
}

int main() {
    string s;
    cin >> s;

    vector<string> answer = generates(s);
    for (const string& str : answer) {
        cout << "\"" << str << "\" ";
    }

    return 0;
}
