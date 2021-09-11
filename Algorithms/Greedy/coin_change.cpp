
// Greedy

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);

using namespace std;

int coinChange(int denominators[], int n, int valToChange) {
    vector<int> ans;
    
    int coins = 0;
    
    sort(denominators, denominators + n, greater<int>());


    for(int i = 0; i < n; ++i) {
        
        int sum = 0; int j = i;
        
        while(j < n) {
        
            if(denominators[j] + sum <= valToChange){
                sum += denominators[j];
                coins++;
                if(sum == valToChange) break;
            }

            else {
                j++;
            }

        }

        ans.push_back(coins);
        coins = 0;

    }

    return *min_element(ans.begin(), ans.end());

}


int main() {

    fastio;

    int denominators[] = {1, 5, 10};
    int valToChange; cin >> valToChange;
    int n = sizeof(denominators) / sizeof(denominators[0]);

    cout << coinChange(denominators, n, valToChange) << "\n";


}