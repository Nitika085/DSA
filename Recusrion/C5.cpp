#include <bits/stdc++.h>
using namespace std;


void solve(string s,string op,   vector<string>& result){
  
    if(s.length()==0){
        result.push_back(op);
        return;
    }

    string op1=op;
    string op2=op;
    op2.push_back(s[0]);
    s.erase(s.begin());
    solve(s,op1,result);
    solve(s,op2,result);
    return ;

}
vector<string>generatesub(string s){
    
     string op="";
     vector<string> result;
     solve(s,op,result);
return result;

}

int main() {
   string s="ab";
vector<string>st =generatesub(s);
  for (string& p:st){
cout<<"\""<<p<<"\" ";
  }

  
    return 0;
}