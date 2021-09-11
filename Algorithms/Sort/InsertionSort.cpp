#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int array[] = {11,13,7,12,16,9,24,5,10,3};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Array before InsertionSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

    for(int firstUnsortedIndex = 1; firstUnsortedIndex < size ; firstUnsortedIndex++){

        int newElement = array[firstUnsortedIndex];
        int i;

        for(i=firstUnsortedIndex-1 ; i>=0 && array[i]>newElement ; i--){
            array[i+1] = array[i];
        }

        array[i+1] = newElement;

    }

    cout << "Array after InsertionSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

}