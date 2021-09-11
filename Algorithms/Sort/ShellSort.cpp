#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int array[] = {56,-1,5,43,67,99,4};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    cout << "Array before ShellSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;

    for(int gap = arrayLength/2; gap>0 ; gap /= 2){

        for(int i = gap; i<arrayLength ; i++){

            int newElement = array[i];

            int j = i;

            while (j >= gap && array[j-gap] > newElement)
            {
                array[j] = array[j-gap];
                j = j - gap;
            }

            array[j] = newElement;
            
        }
        
    }

    cout << "Array after ShellSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;
}