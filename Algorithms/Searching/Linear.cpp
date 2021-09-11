#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int LinearRecursive(int arr[], int index, int val)
{
    if(index < 0)
    {
        return -1;
    }

    if(arr[index] == val)
    {
        return index;
    }
    else
    {
        LinearRecursive(arr,index-1,val);
    }
}


int Linear(int arr[], int arrLength,int val)
{
    for(int i=0; i<arrLength; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }

    return -1;
}

int main(){
    int array[] = {11,13,7,12,16,9,24,5,10,3};
    int size = (sizeof(array) / sizeof(array[0]));

    cout << Linear(array,size,16) << "\n";
    cout << LinearRecursive(array,size-1,16) << "\n";
    
}