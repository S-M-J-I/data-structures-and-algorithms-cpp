#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);


using namespace std;

int max(const int a, const int b) {
    return a > b ? a : b;
}

void ZeroOneKnapsack(const int price[], const int weight[], const int n, const int kW) {

    // take an aux array for memoization
    int k[n+1][kW+1];

    // for i upto all objects
    for(int i = 0 ; i <= n; ++i) {

        // for w upto the max weight of the knapsack
        for(int w = 0; w <= kW; ++w) {

            // if 0 weight or price, assign 0 (taking nothing)
            if(i == 0 || w == 0) {
                k[i][w] = 0;
            }

            // if the weight of item i is less than or equal to current total weight
            else if (weight[i] <= w) {
                // find the max between the value of the previous row and the (price of current item * price of prev item with the current weight - item weight)
                k[i][w] = max( price[i]+k[i-1][w-weight[i]] , k[i-1][w] );
            }

            // else just assign the value of the previous row
            else {
                k[i][w] = k[i-1][w];
            }
        }

    }



    int sum = 0;

    // traverse from bottom up
    int i = n, j = kW;
    while(i > 0 && j > 0) {

        // if prev and current value is equal, 0 (dont take)
        if(k[i][j] == k[i-1][j]) {
            cout << i << ": 0\n";
            i--;
        }

        // else take
        else {
            cout << i << ": 1\n";
            sum += price[i];
            i--;
            j -= weight[i];
        }
    }

    cout << "Sum: " << sum << "\n";

}



int main() {

    fastio;

    int price[] = { 50, 30, 35, 60 };
    int weight[] = { 2, 2, 1, 3 };
    int W = 5;
    int n = sizeof(price) / sizeof(price[0]);
    
    ZeroOneKnapsack(price, weight, n, W);

}