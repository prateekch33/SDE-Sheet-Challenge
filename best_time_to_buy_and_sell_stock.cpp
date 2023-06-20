#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit=0;
    int minp=INT_MAX;
    for(int i=0;i<prices.size();i++) {
        minp=min(minp,prices[i]);
        profit=max(profit,prices[i]-minp);
    }
    return profit;
}
