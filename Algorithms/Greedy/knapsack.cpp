#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);


using namespace std;


struct Item {
    int value, weight;

    Item(){}

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(const Item a, const Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}


double FractionalKnapsack(int Weight, Item arr[], int n) {

    int finalValue, currentWeight;
    finalValue = currentWeight = 0;

    sort(arr, arr + n, cmp);

    for(int i = 0 ; i < n; ++i) {
        if(currentWeight + arr[i].weight <= Weight) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }

        else {
            int remain = Weight - currentWeight;
            finalValue += (arr[i].value * ( (double)remain / (double)arr[i].weight ));
            break;
        }
    }

    return finalValue;

}



int main() {

    int n; int W;
    cin >> n >> W;
    Item items[n];

    for(int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    cout.precision(10);
    cout << FractionalKnapsack(W, items, n) << "\n";
    
}