
/* e^5 = 1 + (x)/1 + (x)^2/2! ...... */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>

using namespace std;

double s=0;

int factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

double TaylorSeries(int limit, int x)
{
    double Taylor = pow(x,limit) / factorial(limit);
    if(limit>=0)
    {
        s = s + Taylor;
        limit--;
        TaylorSeries(limit, x);
    }

    return s;
}

int main()
{
    cout << "Taylor Series : " << TaylorSeries(5,5) << endl;
}