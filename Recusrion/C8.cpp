#include <bits/stdc++.h>
using namespace std;

void solve(string s,string op,vector<string>& res){
if(s.length()==0){
    res.push_back(op);
    return;
}

string op1=op;
string op2=op;

op1.push_back(s[0]);

op2.push_back(toupper(s[0]));
s.erase(s.begin());
solve(s,op1,res);
solve(s,op2,res);


}

vector<string>generates(string p){
    string op="";
   

    vector<string>res;

 solve (p,op,res);
 return res;
}

int main() {
    string s;
    cin>>s;

vector<string>answer;
    answer=generates(s);
    for (const string& str : answer) {
        cout << "\"" << str << "\" ";
    }
    
        return 0;
}