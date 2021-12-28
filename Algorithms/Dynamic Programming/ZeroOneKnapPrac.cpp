#include<bits/stdc++.h>

using namespace std;

void ZeroOneKnap(vector<int>& p, vector<int>& w, int W) {
    int dp[p.size()+1][W+1];

    for(int i = 0; i <= p.size(); ++i) {
        for(int j = 0; j <= W; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            else if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], p[i-1] + dp[i-1][j-w[i-1]]);
            }

            else {
                dp[i][j] = dp[i-1][j];
            }
        } 
    }

    int sum = 0;

    // traverse from bottom up
    int i = p.size(), j = W;
    while(i > 0 && j > 0) {

        // if prev and current value is equal, 0 (dont take)
        if(dp[i][j] == dp[i-1][j]) {
            cout << i << ": 0\n";
            i--;
        }

        // else take
        else {
            cout << i << ": 1\n";
            sum += p[i];
            i--;
            j -= w[i];
        }
    }

    cout << "Sum: " << sum << "\n";

}


int main(){

    vector<int> price = { 50, 30, 35, 60 };
    vector<int> weight = { 2, 2, 1, 3 };
    int W = 5;
    
    ZeroOneKnap(price, weight, W);
    

    return 0;
}