#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);


using namespace std;

struct Activity {
    string name;
    int start, finish;

    Activity(string name, int start, int finish) {
        this->name = name;
        this->start = start;
        this->finish = finish;
    }
};

bool compare(Activity activity1, Activity activity2) {
    return activity1.finish < activity2.finish;
}

void ActivitySelctor(const vector<Activity>& times) {

    vector<Activity> A;

    sort(times.begin(), times.end(), compare);

    int n = times.size();
    int i = 0;

    for(int m = 1; m < n; ++m) {
        if(times[m].start >= times[m].finish) {
            A.push_back(times[m]);
            i = m;
        }
    }

    for(Activity a : times) {
        cout << a.name << "\n";
    }

}


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