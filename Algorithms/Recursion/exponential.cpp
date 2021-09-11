#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int expo(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return expo(m, n-1)*m;
    }
    
}

int main()
{
    cout << expo(2,5) << endl;
}