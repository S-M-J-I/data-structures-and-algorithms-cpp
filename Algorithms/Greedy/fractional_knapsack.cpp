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

bool compare(const Item item1, const Item item2) {
    double ratio1 = (double)item1.value / (double)item1.weight;
    double ratio2 = (double)item2.value / (double)item2.weight;
    return ratio1 > ratio2;
}


double FractionalKnapsack(const int Weight, vector<Item> items, const int n) {

    double finalValue, currentWeight;
    finalValue = currentWeight = 0.0;

    sort(items.begin(), items.end(), compare);

    for(int i = 0 ; i < n; ++i) {
        if(currentWeight + items[i].weight <= Weight) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }

        else {
            int remainingWeight = Weight - currentWeight;
            finalValue += (items[i].value * ( (double)remainingWeight / (double)items[i].weight ));
            break;
        }
    }

    return finalValue;

}



int main() {

    fastio;

    int n; int W;
    cin >> n >> W;
    vector<Item> items(n);

    for(int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    printf("%.3lf\n", FractionalKnapsack(W, items, n));
    
}