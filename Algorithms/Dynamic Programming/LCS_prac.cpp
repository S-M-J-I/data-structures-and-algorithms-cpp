#include<bits/stdc++.h>

using namespace std;

int dp[100][100];


string print_lcs(string S, string T, int m, int n) {

    // return an empty string if the end of either sequence is reached
    if(m == 0 || n == 0) {
        return "";
    }

    // if the last character of `S` and `T` matches
    if (S[m-1] == T[n-1]){

        // append current character (`S[m-1]` or `T[n-1]`) to LCS of
        // substring `S[0…m-2]` and `T[0…n-2]`
        
        return print_lcs(S,T,m-1,n-1) + S[m-1];
    }

    // otherwise, if the last character of `S` and `T` are different
 
    // if a top cell of the current cell has more value than the left
    // cell, then drop the current character of string `S` and find LCS
    // of substring `S[0…m-2]`, `T[0…n-1]`

    if (dp[m-1][n] > dp[m][n-1]) {
        return print_lcs(S, T, m-1, n);
    }

    else {
        // if a left cell of the current cell has more value than the top
        // cell, then drop the current character of string `T` and find LCS
        // of substring `S[0…m-1]`, `T[0…n-2]`

        return print_lcs(S, T, m, n-1);
    }
}


void LCS(string S, string T) {
    int m = S.length();
    int n = T.length();

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {

            if(S[i-1] == T[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        } 
    }

    cout << print_lcs(S, T, m, n) << "\n";
}


int main() {
    LCS("XMJYAUZ", "MZJAWXU");
}