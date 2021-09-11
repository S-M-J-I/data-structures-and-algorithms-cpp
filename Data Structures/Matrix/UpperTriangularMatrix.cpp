#include <bits/stdc++.h>

using namespace std;

class UpperTriangularMatrix
{
    private:
    int n;
    int *A;

    public:

    UpperTriangularMatrix(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    void set(int i, int j, int element)
    {
        if(i <= j)
        {
            // Column Major mapping
            A[j*(j-1)/2+i-1] = element; 
        }
    }

    int get(int i, int j)
    {
        if(i <= j)
        {
            return A[j*(j-1)/2+i-1];
        }

        return 0;
    }

    void display()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i <= j)
                {
                    cout << A[j*(j-1)/2+i-1] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }

    int getDimension()
    {
        return this->n;
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    UpperTriangularMatrix um = UpperTriangularMatrix(3);

    for(int i=1; i<=um.getDimension(); i++)
    {
        for(int j=1; j<=um.getDimension(); j++)
        {
            int x; cin >> x;
            um.set(i,j,x);
        }
    }

    um.display();
}