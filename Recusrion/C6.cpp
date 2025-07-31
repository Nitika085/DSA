#include <bits/stdc++.h>
using namespace std;


void solve(string s,string op, unordered_set<string>& count){
  
    if(s.length()==0){
        count.insert(op);
        return;
    }

    string op1=op;
    string op2=op;
    op2.push_back(s[0]);
    s.erase(s.begin());
    solve(s,op1,count);
    solve(s,op2,count);
    return ;

}
vector<string>generatesub(string s){
    unordered_set<string>count;
     string op="";
     vector<string> result;
     solve(s,op,count);
     for( const string& st: count){
        result.push_back(st);
     }
return result;

}

int main() {
   string s="aab";
vector<string>st =generatesub(s);
  for (string& p:st){
cout<<"\""<<p<<"\" ";
  }

  
    return 0;
}