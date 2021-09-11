#include<iostream>
//#include<stdio.h>
#include<cstdlib>

using namespace std;


void fun(int n)
{

    while(n>0)
    {
        cout << n << " ";
        n--;
    }
}

int main()
{
    int x=3;
    fun(x);
    return 0;
    
}