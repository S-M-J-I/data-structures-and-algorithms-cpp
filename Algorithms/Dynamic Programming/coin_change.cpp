#include <bits/stdc++.h>

using namespace std;

// total ways
int coinChange(vector<int> &coins, int S)
{
    int n = coins.size();

    int coinTable[S + 1] = {0};

    coinTable[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = coins[i]; j <= S; ++j)
        {
            coinTable[j] += coinTable[j - coins[i]];
        }
    }

    return coinTable[S];
}

int minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V + 1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i = 1; i <= V; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++){
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                {
                    table[i] = sub_res + 1;
                }
            }
        }
    }

    if (table[V] == INT_MAX)
        return -1;

    return table[V];
}

int main()
{

    vector<int> coins = {1, 2, 3};
    int S = 4;

    cout << coinChange(coins, S) << "\n";

    return 0;
}