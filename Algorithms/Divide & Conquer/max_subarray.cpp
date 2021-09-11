#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// return the max between 2 ints
int max(int a, int b) { return a > b ? a : b; }

// return the max between 3 ints
int max(int a, int b, int c) { return max(max(a,b), c); }

int maxCrossingSum(int *arr, int l, int m, int h)
{
    int sum = 0;
    int l_sum = INT_MIN;
    for(int i = m; i >= l; i--)
    {
        sum += arr[i];
        if(sum > l_sum)
        {
            l_sum = sum;
        }
    }

    sum = 0;
    int r_sum = INT_MIN;
    for(int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if(sum > r_sum)
        {
            r_sum = sum;
        }
    }

    return max(l_sum + r_sum, l_sum, r_sum);

}

int maxSubArraySum(int *arr, int l, int h)
{
    if(l == h)
    {
        return arr[l];
    }

    int mid = (l + h) / 2;

    return max(maxSubArraySum(arr, l, mid), maxSubArraySum(arr, mid+1, h), maxCrossingSum(arr, l, mid, h));
}

int KadaneAlgorithm(int arr[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for(int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
        } else if (max_ending_here < 0){
            max_ending_here = 0;
        }
    }

    return max_so_far;
}


int main()
{
    fastio;
    int arr[]{ 5, -9, 20, -18, 5, -11, 10, -20, 24 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Max sub-array sum is : " << max_sum << "\n";
    cout << "Max sub-array sum according to Kadane's Algorithm is : " << KadaneAlgorithm(arr, n) << "\n";
}