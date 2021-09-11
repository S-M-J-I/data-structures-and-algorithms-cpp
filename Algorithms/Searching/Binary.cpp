#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int BinaryRecursive(int arr[], int start, int end, int val)
{
    if(start >= end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if(arr[mid] == val)
    {
        return mid;
    }
    else if(arr[mid] > val)
    {
        BinaryRecursive(arr,0,mid,val);
    }
    else
    {
        BinaryRecursive(arr,mid+1,end,val);
    }


}



int Binary(int arr[], int start, int end, int val)
{
    int mid = (start+end)/2;

    while(start < end)
    {
        if(arr[mid] == val)
        {
            return mid;
        }
        else if(arr[mid] > val)
        {
            mid = end;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}


int main()
{
    int array[] = {3,5,6,7,12,14,17,19,23};
    int size = (sizeof(array) / sizeof(array[0]));
    
    cout << Binary(array,0,size-1,12) << "\n";
    cout << BinaryRecursive(array,0,size-1,12) << "\n";

}