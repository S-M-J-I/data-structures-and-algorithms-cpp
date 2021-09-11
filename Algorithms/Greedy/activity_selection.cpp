#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);


using namespace std;

vector<int> ActivitySelctor(const vector<int>& start, const vector<int>& finish) {

    vector<int> A = {0};
    int n = start.size();
    int i = 0;

    for(int m = 1; m < n; ++m) {
        if(start[m] >= finish[i]) {
            A.push_back(m);
            i = m;
        }
    }


    return A;

}


int main() {

    vector<int> start = {1, 1, 0, 4, 3, 4, 5, 2};
    vector<int> finish = {2, 3, 4, 5, 5, 6, 8, 9};

    vector<int> activities = ActivitySelctor(start, finish);

    // activity 0, 3, 6
    for(int i : activities) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}