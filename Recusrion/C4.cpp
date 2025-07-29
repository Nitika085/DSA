#include <bits/stdc++.h>
using namespace std;
void insertS(stack<int>& p, int temp);


void reverseS(stack<int>& st){
    if(st.size()==1)return;
int temp=st.top();
st.pop();
reverseS(st);
insertS(st,temp);

}


void insertS(stack<int>& st,int temp){
if(st.size()==0)st.push(temp);
int val=st.top();
st.pop();
reverseS(st);
insertS(st,temp);
st.push(val);
}

int main() {
    stack<int>st;
    st.push(3);
    st.push(6);
    st.push(7);
    st.push(1);
    st.push(0);
    st.push(2);
    st.push(6);
  
   while(!st.empty()){
        cout<<st.top()<<" ";
            st.pop();
    }
    
    return 0;
}