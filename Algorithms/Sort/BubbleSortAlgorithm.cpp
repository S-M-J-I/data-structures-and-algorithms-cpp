#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int array[] = {56,-1,5,43,67,99,4};
    int array_length = 7;
    int lastUnswappedIndex = array_length-1;
    
    cout << "Array before BubbleSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl;
    
    for(int i=lastUnswappedIndex ; i>=0 ; i--){
        for(int j=0; j<i ; j++){
            if(array[j]>array[j+1]){
                if(j!=j+1){
                    int temp;
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }

    cout << "Array after BubbleSort: ";
    for(auto x : array) cout << x << " ";
    cout << endl; 
}