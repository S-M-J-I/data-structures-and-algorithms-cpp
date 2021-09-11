#include<bits/stdc++.h>
#define fastio #define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void DACEven(int arr[], int l, int h) {

    // case 1: if low and high are same (one value in array after partitioning)
    // and that val is even, print it
    if(l == h && arr[l] % 2 == 0 ) {
        cout << arr[l] << " ";
    }

    // case 2: if low and high are same (one value in array after partitioning)
    // and that val is odd, do nothing and return(stop further execution)
    else if (l == h && arr[l] % 2 != 0 ) {
        return;
    }

    // case 3: if neither, then keep dividing the array until it returns nothing
    // recursion rabbit hole formed in lines 25, 26 will terminate when case 2 condition is met 
    else {
        int mid = (l + h) / 2;
        DACEven(arr, l, mid);
        DACEven(arr, mid+1, h);
    }

}



int main() {
    
    int arr[]{1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    DACEven(arr, 0, size-1);

}