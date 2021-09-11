#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    //INSIDE STACK
    int A[3][4];
    for(int i=0; i<3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
        }
        cout << endl;
    }
    for(int i=0 ; i<3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Row " << i+1 << " Column " << j+1 << ": " << A[i][j] << endl;
        }
        cout << endl;
    }
    delete []A;
    cout << endl;

    //PARTIALLY IN STACK, PARTIALLY IN HEAP
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> B[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Row " << i+1 << " Column " << j+1 << ": " << B[i][j] << endl;
        }
        cout << endl;
    }
    delete []B;

    cout << endl;

    //ALL INSIDE HEAP
    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> C[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Row " << i+1 << " Column " << j+1 << ": " << C[i][j] << endl;
        }
        cout << endl;
    }
    delete []C;
    
}