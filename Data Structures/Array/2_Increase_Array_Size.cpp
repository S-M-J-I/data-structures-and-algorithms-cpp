#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int *p = new int[5];
    int *q = new int[10];

    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    
    for(int i=0 ; i<5 ; i++)
    {
        q[i] = p[i];
    }
    p=q;
    delete []p;

    cout << "Enter 5 more elements: ";
    for(int i=5; i<10 ; i++)
    {
        cin >> p[i];
    }

    for(int i=0 ; i<10 ; i++)
    {
        cout << p[i] << " ";
    }

}