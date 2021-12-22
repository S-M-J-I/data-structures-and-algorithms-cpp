#include<bits/stdc++.h>

using namespace std;


bool subsetSum(vector<int>& A, int N) {

    int n = A.size();

    bool subsetsumTable[n+1][N+1];

    for(int i = 0; i <= n; ++i) {
        subsetsumTable[i][0] = true;
    }

    for(int i = 1; i <= n; ++i) {
        subsetsumTable[0][i] = false;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(A[i-1] > j) {
                subsetsumTable[i][j] = subsetsumTable[i-1][j];
            }

            else {
                subsetsumTable[i][j] = subsetsumTable[i-1][j] || subsetsumTable[i-1][j-A[i-1]];
            }
        }
    }

    return subsetsumTable[n][N];
}



int main(){

    vector<int> A = {2,4,5,6,8};
    int N = 15;

    cout << (subsetSum(A, N) ? "true" : "false") << "\n";

    return 0;
}