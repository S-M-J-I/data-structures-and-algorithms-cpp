#include<bits/stdc++.h>

using namespace std;

vector<int> fibTable = {-1};


/* // top down fibonacci 

int fibonacciHelper(int n) {
    if(n <= 1) {
        return n;
    }
    fibTable[n] = fibonacciHelper(n-1) + fibonacciHelper(n-2);
    return fibTable[n];
}



int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }

    fibTable.assign(n+1, -1);
    fibTable[0] = 0;
    fibTable[1] = 1;
    return fibonacciHelper(n);
}

*/

// bottom-up fibonacci


int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }

    fibTable[0] = 0;
    fibTable[1] = 1;
    for(int i = 2; i <= n; ++i) {
        fibTable[i] = fibTable[i-1] + fibTable[i-2];
    }

    return fibTable[n];
}



int main(){
    cout << fibonacci(4) << "\n";
    return 0;
}