#include<bits/stdc++.h>


using namespace std;

void solvek(stack<int>& p,int k){
if(k==1){p.pop();
return;
}

int temp=p.top();
p.pop();
solvek(p,k-1);
p.push(temp);
}

int main(){
    stack<int>st;
    st.push(3);
    st.push(6);
    st.push(7);
    st.push(1);
    st.push(0);
    st.push(2);
    st.push(6);
    int mid=st.size()/2+1;
    solvek(st,mid);
  while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
  
}