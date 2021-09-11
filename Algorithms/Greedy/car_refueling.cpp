#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define ll long long int

using namespace std;

int main() {
    fastio;

    ll d, m; cin >> d >> m;
    int n; cin >> n;

    vector<ll> gasStations;

    gasStations.push_back(0);
    for(int i = 1 ; i <= n; i++) {
        int x; cin >> x;
        gasStations.push_back(x);
    }
    gasStations.push_back(d);

    ll nrefuel = 0, currRefuel = 0;

    while(currRefuel <= n) {
        int prevRefuel = currRefuel;

        while(currRefuel <= n && (gasStations[currRefuel + 1] - gasStations[prevRefuel] <= m) ) {
            currRefuel++;
        }

        if(currRefuel == prevRefuel) {
            nrefuel = -1;
            break;
        }

        if(currRefuel <= n) {
            nrefuel++;
        }

    }

    cout << nrefuel << "\n";

}