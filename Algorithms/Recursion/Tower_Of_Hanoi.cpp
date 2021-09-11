#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
int count = 0;
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout << "Move disc from " << A << " to " << C << endl;
        count++;
        TOH(n-1,B,A,C);
    }
}

int main()
{
    TOH(3,1,2,3);
    cout << "\nSolved! Tower Complete" << endl;
    cout << "Moves made : " << count <<  endl;
}