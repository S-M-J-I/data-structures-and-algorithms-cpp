#include<bits/stdc++.h>

using namespace std;

int findMax(int A[], int n)
{
    int max = A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
        
    }

    return max;
}

void Countsort(int A[], int n)
{
    //find maximum element of the array, this is the array size
    int max = findMax(A,n);
    int i,j; // C and A list iterators respectively
    //create a new array with max+1
    int *C = new int[max+1];

    //initialize all values in C to 0
    for(int i=0; i<max+1; i++)
    {
        C[i] = 0;
    }

    //count values in C array ++
    for(int i=0; i<n; i++)
    {
        C[A[i]]++;
    }

    //declare 0
    i=0, j=0;
    //while i<max+1
    while(i < max+1)
    {   
        //if C[i] is > 0
        if(C[i]>0)
        {
            // put that index value as element in A, increase the iterator of a by +1
            A[j++] = i;
            //decrement the C[i] element
            C[i]--;
        }
        else
        {
            //else just move to next
            i++;
        }
    }
    
}


int main()
{
    cin.tie(0);
    cout.tie(0);

    int arr[] = {6,3,9,10,15,6,8,12,3,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before CountSort : \n";
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";

    Countsort(arr,size);

    cout << "After CountSort : \n";
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
}