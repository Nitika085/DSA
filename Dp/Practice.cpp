#include <bits/stdc++.h>
using namespace std;

int Profixtmax(const vector<int>& prices){
    int maximumProfit=0;
    int n=prices.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;++j){
            int profit=prices[j]-prices[i];
            if(profit>maximumProfit){
                maximumProfit=profit;
            }
        }
    }
    return maximumProfit;

}



int Profitmaxoptimal(const vector<int>& prices){
    int minPrice=INT_MAX;
    int maximumuProfit=0;

    for(int price:prices){
        if(price<minPrice){
            minPrice=price;
        }
        else{
            maximumuProfit=max(maximumuProfit,price-minPrice);
        }
    }
    return maximumuProfit;
}

int profitMaxVersion(const vector<int>& prices){
    int profit=0;

    for(int i=i;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
        }
    }
    return profit;
}
int main() {
   vector<int>prices={1,7,6,8,4,6,2,22,7,9,2};

    int answer=profitMaxVersion(prices);

    cout<<answer;
    
    return 0;
}