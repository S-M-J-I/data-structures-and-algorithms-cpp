#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

void LCS(string S, string T) {
    int m = S.length();
    int n = T.length();
    string finalStr = ""; // answer string

    // memoization table
    int LCS[m+1][n+1];

    // from S 0 -> m
    for(int i = 0; i <= m; ++i) {
        
        // T 0 -> n
        for(int j = 0 ; j <= n; ++j) {

            // if chars are equal
            if(S[i] == T[j]) {
                // 1 + prev diagonal element
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }

            else {
                // else find the max between up and left
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    int i = m, j = n;

    // traverse table from bottom-up
    while(i > 0 && j > 0) {

        // if current > prev diagonal, add that char to final string and move to the prev diagonal
        if(LCS[i][j] > LCS[i-1][j]) {
            finalStr.push_back(S[i]);
            i--; j--;
        }

        // else if the current = its back / left element, move to the left
        else if (LCS[i][j] == LCS[i-1][j]) {
            i--;
        }

    }

    // print string in rev because we filled the table from bottom-up
    for(int i = finalStr.length(); i >= 0; i--) {
        cout << finalStr[i] << "";
    }

    cout << "\n";

}



int main() {

    LCS("ADAPT", "DBPT");

}