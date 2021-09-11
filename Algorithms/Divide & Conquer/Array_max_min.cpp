#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int getMin(int a, int b)
{
    return a < b ? a : b;
}

int * MaxMin(int A[], int i, int j)
{
    cout << i << " " << j << "\n";
    int * result = new int[2];
    int max, min, max1, max2, min1, min2;

    if(i == j) {
        max = min = A[i];
    }

    else {

        int mid = (i + j) / 2;
        int * result1 = MaxMin(A, i, mid);
        int * result2 = MaxMin(A, mid+1, j);
        max1 = result1[0];
        min1 = result1[1];
        max2 = result2[0];
        min2 = result2[1];

        max = getMax(max1, max2);
        min = getMin(min1, min2);

        delete result1;
        delete result2;
    }

    result[0] = max;
    result[1] = min;
    cout << max << " " << min << "\n";
    return result;
}



int main()
{
    int arr[] = {22,13,-5,-8,15,60,17,31,47};
    int size = sizeof(arr) / sizeof(arr[0]);

    int * res = MaxMin(arr, 0, size-1);

    cout << "\n\nFinal: "; 
    cout << res[0] << " " << res[1] << "\n";

    delete res;

}