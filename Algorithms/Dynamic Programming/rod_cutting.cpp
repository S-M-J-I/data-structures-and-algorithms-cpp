#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}


int rodCutting(int price[], int max_length)
{

    int rod_length = max_length;

    int maxPriceArray[max_length+1][rod_length+1];
    for(int i = 0; i <= rod_length; ++i) {
        for(int j = 0; j <= max_length; ++j) {
            maxPriceArray[i][j] = 0;
        }
    }

    for(int i = 1; i <= rod_length; ++i) {
        for(int j = 1; j <= max_length; ++j) {
            if(j < i) {
                maxPriceArray[i][j] = maxPriceArray[i-1][j];
                continue;
            }

            maxPriceArray[i][j] = max(maxPriceArray[i-1][j] , price[i-1] + maxPriceArray[i][j-i]);
        }
    }

    for(int i = 0 ; i <= rod_length; ++i) {
        for(int j = 0 ; j <= max_length ; ++j ) {
            cout << maxPriceArray[i][j] << " ";
        }
        cout << "\n";
    }



    return maxPriceArray[rod_length-1][max_length];

}

int un_kp(int price[], int length[], int Max_len, int n)
{
    int t[9][9];

    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene  we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len] = max(price[n - 1] + un_kp(price, length, Max_len - length[n - 1], n), un_kp(price, length, Max_len, n - 1));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        t[n][Max_len] = un_kp(price, length, Max_len, n - 1);
    }

    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_lenth column.
    return t[n][Max_len];
}

int main()
{

    fastio;

    int price[] = {2, 5, 5, 9, 12, 14, 17, 19, 21};
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int max_length = 9;

    cout << rodCutting(price, max_length) << "\n";

    cout << un_kp(price, length, 9, max_length) << "\n";
}