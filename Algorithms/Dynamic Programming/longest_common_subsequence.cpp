#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}


int LCS[100][100];

string LCSPrint(string S, string T, int m, int n)
{

    if (m == 0 || n == 0) {
        return string("");
    }
 

    if (S[m - 1] == T[n - 1])
    {
        return LCSPrint(S, T, m - 1, n - 1) + S[m - 1];
    }
 
 
    if (LCS[m - 1][n] > LCS[m][n - 1]) {
        return LCSPrint(S, T, m - 1, n);
    }
    else {
        return LCSPrint(S, T, m, n - 1);
    }
}

string LCSAction(string S, string T) {
    int m = S.length();
    int n = T.length();


    // from S 0 -> m
    for(int i = 1; i <= m; ++i) {
        
        // T 0 -> n
        for(int j = 1 ; j <= n; ++j) {

            // if chars are equal
            if(S[i-1] == T[j-1]) {
                // 1 + prev diagonal element
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }

            else {
                // else find the max between up and left
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    return LCSPrint(S,T,m,n);

}


int main() {

    cout << LCSAction("XMJYAUZ", "MZJAWXU");

}