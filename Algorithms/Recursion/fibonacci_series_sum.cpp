#include<bits/stdc++.h>

using namespace std;

int fibonacci_series_sum(int n) {
    if(n <= 1) {
        return n;
    }

    return fibonacci_series_sum(n-1) + fibonacci_series_sum(n-2);
}

int main() {
    int n; cin >> n;

    cout << fibonacci_series_sum(n) << "\n";
}