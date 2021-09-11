#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int array[] = {11,13,7,12,16,9,24,5,10,3};
    int size = (sizeof(array) / sizeof(array[0]));

    cout << "Array before SelectionSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

    int i,j,k;
    for(i=0; i<size-1; i++)
    {
        for(j=k=i; j<size; j++)
        {
            if(array[k] > array[j])
            {
                k = j;
            }
        }
        swap(&array[i],&array[k]);
    }

    cout << "Array after SelectionSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;
}