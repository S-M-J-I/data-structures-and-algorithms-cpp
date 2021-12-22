#include<bits/stdc++.h>

using namespace std;


int coinChange(vector<int>& coins, int S) {
    int n = coins.size();

    int coinTable[S+1] = {0};

    coinTable[0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = coins[i]; j <= S; ++j) {
            coinTable[j] += coinTable[j-coins[i]];
        }
    }


    return coinTable[S];
}


int main(){

    vector<int> coins = {1,2,3};
    int S = 4;

    cout << coinChange(coins, S) << "\n";

    return 0;
}