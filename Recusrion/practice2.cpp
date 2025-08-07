#include <bits/stdc++.h>
using namespace std;

int swapfruits(vector<int>&basket1,vector<int>&basket2){

map<int,int>count;
for(int fruits:basket1)count[fruits]++;
for(int fruits:basket2)count[fruits]--;

vector<int>extra;
    int min_val = INT_MAX;

for(auto const&[fruits,counts]:count){
   if(counts%2!=0)return -1;
   int need=abs(counts)/2;
   for(int i=0;i<need;i++){
    extra.push_back(fruits);
   }
   min_val=min(min_val,fruits);
}
int cost=0;
sort(extra.begin(),extra.end());
int m=extra.size();
for (int i = 0; i < m / 2; ++i) {
        cost += min(extra[i], 2 * min_val);
    }

    return cost;



}

int main() {
   vector<int>b1={1,9,9};
   vector<int>b2={1,8,8};
   int x=swapfruits(b1,b2);
   cout<<x;
    return 0;
    
}