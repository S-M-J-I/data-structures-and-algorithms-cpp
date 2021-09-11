#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// return the min between 2 ints
int min(int a, int b) { return a < b ? a : b; }

// return the min between 3 ints
int min(int a, int b, int c) { return min(min(a,b), c); }

int minCrossingSum(int *arr, int l, int m, int h)
{
    int sum = 0;
    int l_sum = INT_MAX;
    for(int i = m; i >= l; i--)
    {
        sum += arr[i];
        if(sum < l_sum)
        {
            l_sum = sum;
        }
    }

    sum = 0;
    int r_sum = INT_MAX;
    for(int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if(sum < r_sum)
        {
            r_sum = sum;
        }
    }

    return min(l_sum + r_sum, l_sum, r_sum);

}

int minSubArraySum(int *arr, int l, int h)
{
    if(l == h)
    {
        return arr[l];
    }

    int mid = (l + h) / 2;

    return min(minSubArraySum(arr, l, mid), minSubArraySum(arr, mid+1, h), minCrossingSum(arr, l, mid, h));
}




int main()
{
    fastio;
    int arr[]{ 3, -4, 2, -3, -1, 7, -5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_sum = minSubArraySum(arr, 0, n - 1);
    cout << "min sub-array sum is : " << min_sum << "\n";
}