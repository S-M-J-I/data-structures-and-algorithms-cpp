#include <bits/stdc++.h>

using namespace std;

//Type 1: merging two lists in another list
void mergeType1(int A[], int B[], int sizeA, int sizeB)
{
    //declare an array C to keep two merged lists
    int C[sizeA+sizeB];
    //initalise i,j,k to 0
    /*here:
        i is the index of A list
        j is the index of B list
        k is the index of merged list (C list)
    */
    int i,j,k;
    i=j=k=0;

    while(i<sizeA && j<sizeB) // while i is less than A list size & j is less than B list size
    {
        //if A[i] < B[j], if true, assign A[i] to C[k] then increment both, else assign B[j] to C[k] the increment both
        C[k++] = (A[i] < B[j]) ? A[i++] : B[j++];
    }
    //check for remaining elements in A list, if there is, copy all elements to C list
    for(; i<sizeA; i++){
        C[k++] = A[i];
    }
    //same for B list
    for(; j<sizeB; j++){
        C[k++] = A[j];
    }
}


//Type 2: merging in a single list
void mergeType2(int A[], int l, int mid, int h){
    //take i(index of left side) as low
    //take j(index of right side) as mid+1
    //take k(index of temp list) as low
    int i=l, j=mid+1, k=l;
    int B[100];
    
    //i will go from l -> mid
    //j will go from mid+1 -> h

    while(i<=mid && j<=h){
        B[k++] = (A[i] < A[j]) ? A[i++] : A[j++];
    }

    for(; i<=mid; i++){
        B[k++] = A[i];
    }
    for(; j<=h; j++){
        B[k++] = A[j];
    }

    //copy back
    for(int x=l; x<=h; x++){
        A[x] = B[x];
    }

}

void IterativeMerge(int A[], int n)
{
    //take p, l, h, mid, i
    //p is the processes to break list
    //l is the start of each list
    //h is the end of each list
    //mid is the middle index of each broken list
    //i is the iterator from 0 -> list end
    int p,l,h,mid,i;

    //for process to break down list
    for (p=2; p<=n; p*=2)
    {
        //for 0 -> n
        for(i=0; i+p-1 < n; i+=p)
        {
            //set l as first index of list
            l = i;
            //set h as last index of list
            h = i+p-1;
            //mid is the half
            mid = (l+h) / 2;
            //call merge with one list
            mergeType2(A,l,mid,h);
        }
    }
    //if odd elements are there
    if(p/2<n){
        //call merge
        //start from 0 -> n and mid is the processNow -1
        mergeType2(A,0,p/2-1,n);
    }
}


void RecursiveMerge(int A[], int l, int h)
{
    //take a variable to store midpoint
    int mid;
    //if low is less than high
    if(l<h)
    {
        //calc mid
        mid = (l+h)/2;
        //keep calling until l>h --- sort right side
        RecursiveMerge(A,l,mid);
        //keep calling until l>h --- sort left side
        RecursiveMerge(A,mid+1,h);
        //merge the entire list
        mergeType2(A,l,mid,h);
    }
}


int main()
{
    int array[]={11,13,7,12,16,9,24,5,10,3};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    cout << "Array before MergeSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

    //Iterative Merge Sort
    IterativeMerge(array,arrayLength);

    cout << "Array after MergeSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

    int array2[] = {11,13,7,12,16,9,24,5,10,3};
    int array2Length = sizeof(array2) / sizeof(array2[0]);

    cout << "Array before MergeSort: ";
    for(auto x : array2) cout << x << " ";
    cout << endl;

    //Iterative Merge Sort
    RecursiveMerge(array,0,arrayLength-1);

    cout << "Array after MergeSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

}



