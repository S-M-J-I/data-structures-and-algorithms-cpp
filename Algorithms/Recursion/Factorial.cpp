#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int fact(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return fact(n-1)*n;
    }
    
}

int main()
{
    int ans = fact(5);
    cout << ans << endl;
}