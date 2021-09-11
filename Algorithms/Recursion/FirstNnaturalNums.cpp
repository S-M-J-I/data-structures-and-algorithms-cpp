#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int s=0;

/* My Method
int Natural(int n)
{
    if(n>0)
    {
        s = s + n;
        Natural(n-1);
    }

    return s;
}
*/

/* Fastest Method
int sum(int n)
{
    return n*(n+1) / 2;
}
*/

/* Loop Method
int sum(int n)
{
    int i;
    for(i=1; i<=n ; i++)
    {
        s = s + i;
    }
    return s;
}
*/


//Recursive Method
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return sum(n-1)+n;
    }
    
}


int main()
{
    int n;
    cin >> n;
    int r = sum(n);
    cout << "Sum of first " << n << " numbers is " << r << endl;
}