#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);

using namespace std;

struct Activity {
    int name;
    int start, finish;

    Activity(int name, int start, int finish) {
        this->name = name;
        this->start = start;
        this->finish = finish;
    }
};

// comapre function: sort in ascending order of finishing time
bool compare(Activity* activity1, Activity* activity2) {
    return activity1->finish < activity2->finish;
}


void ActivitySelector(vector<Activity*>& times) {

    // take a list of activites
    vector<Activity*> A;

    // sort it in ascending order of finishing times
    sort(times.begin(), times.end(), compare);

    int n = times.size();
    int i = 0;

    A.push_back(times[i]);
    // for all activites starting from 1 to n (let the starting activity be 0)
    for(int m = 1; m < n; ++m) {
        // if we find that the current activity's start is greater than
        if(times[m]->start >= times[i]->finish) {
            A.push_back(times[m]);
            i = m;
        }
    }

    for(Activity *a : A) {
        cout << a->name << " ";
    }
    cout << "\n";

}


int main() {

    vector<int> start = {1, 1, 0, 4, 3, 4, 5, 2};
    vector<int> finish = {2, 3, 4, 5, 5, 6, 8, 9};

    vector<Activity*> activities;

    int n = 0;
    for(int i = 0; i < start.size(); ++i) {
        activities.push_back(new Activity(n++, start[i], finish[i]));
    }

    ActivitySelector(activities);

    return 0;
}