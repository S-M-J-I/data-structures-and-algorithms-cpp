#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void Insert(int A[], int n)
{
    // take a temp variable and i variable. temp for current target element, i for index to swap
    int temp, i=n;
    // assign target element to temp, and current index n to i
    temp = A[n];

    // while i>1 and while the temp variable is greater than its parent
    while(i > 1 && temp>A[i/2])
    {
        // swap postions of the current variable with its parent variable 
        A[i] = A[i/2];
        // make the current index its parent now
        i = i/2;
    }
    // finally, assign the temp variable at the current postion of i
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    // start from 2 because 2 is the minimum value a child can be when being divided by 2 to find parent   
    for(int i=2; i<=n; i++)
    {
        // call insert
        Insert(A,i);
    }
}

int Delete(int A[], int n)
{
    // Declare i,j,x
    int x,i,j;
    int val = A[1];

    // take the last element in the heap array as x
    x = A[n];
    // swap last position w/ first and first w/ last
    A[1] = A[n];
    A[n] = val;
    // assign i to 1, and j to i's child (2*i)
    i = 1, j = 2*i;
    // while j does not reach before the positon of the last element
    while(j < n-1){
        // check if right child is greater than left child. If yes, then move j to the right child
        if(A[j+1] > A[j]) j++;
        // check if parent is less than child, if yes
        if(A[i] < A[j]){
            // swap parent and child
            swap(A[i],A[j]);
            // make parent's index child's index
            i = j;
            // make child's index the next child's index
            j = 2*j;
        }
        // else, do nothing, break
        else
        {
            break;
        }
    }
    return val;
}

void showHeap(int A[], int n)
{
    cout << "Heap: ";
    // display the heap
    for(int i=1; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main()
{
    
    int A[] = {0,10,20,30,25,5,40,35};
    int n = sizeof(A) / sizeof(A[0]);
    createHeap(A,n);
    showHeap(A,n);


    // Heap Sort
    for(int i=n-1; i>1;i--){
        Delete(A,i);
    }

    showHeap(A,n);
}