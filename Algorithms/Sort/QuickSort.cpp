#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int start, int end)
{
    int pivot = A[start];
    int i = start, j = end;

    do{
        //increase i by 1 while the element at i is less or equal to pivot (i looks for element greater than the pivot), if otherwise, stop
        do{i++;}while(A[i] <= pivot);
        //decrease j by 1 while the element at j is greater than pivot (j looks for element smaller than the pivot), otherwise stop
        do{j--;}while(A[j] > pivot);
        //if i is less than j i.e. they have not crossed each other in the list yet,
        //swap 
        if(i<j){
            swap(&A[i],&A[j]);
        }

    }while (i<j); // keep doing it until i and j cross each other
    
    swap(&A[start],&A[j]); // then swap the starting element with element at j
    return j; // return j, because j is the partitioning position
}

void QuickSort(int A[], int start, int end){
    int j;

    if(start<end){
        //store the parition index at j variable
        j = partition(A,start,end);
        QuickSort(A,start,j); // quicksort the left part from start -> partitioning position
        QuickSort(A,j+1,end); // quicksort the right part from partitioning postion+1 -> end
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int array[]={11,13,7,12,16,9,24,5,10,3};
    int array_length = (sizeof(array)) / (sizeof(array[0]));
    int i;
    cout << "Array Before Quicksort: \n";
    for(i=0; i<array_length; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    QuickSort(array,0,array_length);

    cout << "Array After Quicksort: \n";
    for(i=0; i<array_length; i++){
        cout << array[i] << " ";
    }
    
}