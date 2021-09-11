#include<bits/stdc++.h>

#define REP(i,a,b) for(int i=a; i<b; i++)

using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(struct Array *arr) {
    cout << "Elements are : ";
    for(int i=0; i<arr->length; i++){
        cout << arr->A[i] << ", ";
    }
    cout << endl;
}

void Append(struct Array *arr, int x) {
    //if array length is less than size
    if(arr->length < arr->size){
        //add element to back of the array, then increment the length by +1
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x) {
    
    //if index is less than size and length; and greater than 0
    if(index < arr->size && index <= arr->length && index>=0){
        //from length to just after index
        for(int i=arr->length; i>index; i--){
            //shift all the elements to the LEFT
            arr->A[i] = arr->A[i-1];
        }

        //insert x at index pos
        arr->A[index] = x;
        //increase length
        arr->length++;
    }
}

int Search(struct Array *arr, int x) {
    
    for(int i=0; i<arr->length; i++){
        if(x == arr->A[i]) {
            return i;
        }
    }

    return -1;
}

void Delete(struct Array *arr, int x){
    int index = Search(arr,x);
    if(index!=-1){
        for(int i=index; i<arr->length; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }else{
        cout << "Couldn't delete, no such element in the array" << endl;
    }
}

int BinarySearch(struct Array arr, int key) {
    //declare start as 0
    int start = 0;
    //end as the last index
    int end = arr.length-1;

    //while start is less than the end i.e, when we've traversed the entire array
    while (start <= end)
    {
        int mid = (start+end) / 2;
        if(key == arr.A[mid]) {
            return mid;
        }else if ( key < arr.A[mid]) {
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }
    
    return -1;
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // create array, {elements} . {size} . {length}
    struct Array arr={{3,2,6,5,4},10,5};
    int n = arr.length;
    
    Insert(&arr,5,10);
    // Append(&arr,10);

    Display(&arr);

    Delete(&arr,4);
    Delete(&arr,7);

    Display(&arr);

}






