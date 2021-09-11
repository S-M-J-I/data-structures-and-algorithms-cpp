#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int A[5]; //fixed size stored at stack

    //declaring size of array at run time, stored at stack
    int n;
    cin >> n;
    int B[n];


    //DECLARING ARRAY IN HEAP MEMORY
    int *p = new int[5]; //in C++
    int *q = (int * ) malloc( 5 * sizeof(int) ); //in C

    //ACCESSING AN ARRAY ELEMENT IN HEAP
    A[0] = 5;
    p[0] = 5;
    p[1] = 4;
    p[2] = 5;
    p[3] = 4;
    p[4] = 4;
    q[0] = 5;
    //as easy 

    //PRINTING HEAP ARRAY
    for(int i=0; i<5; i++){
        cout << p[i] << endl;
    }

    //AFTER DECLARING, DELETE THE ARRAY TO PREVENT MEMORY LEAK
    delete []p; //in C++
    free(q); //in C

}