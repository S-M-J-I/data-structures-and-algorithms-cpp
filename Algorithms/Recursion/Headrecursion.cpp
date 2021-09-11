#include<iostream>

using namespace std;

/* **USING IF**
void fun(int n)
{
    if(n>0)
    {
        fun(n-1);
        cout << n << " ";
    }

}
*/

//Using LOOP
void fun(int n)
{
    int i=1;
    while(i<=n)
    {
        cout << i << " ";
        i++;
    }
}


int main()
{
    fun(3);
}