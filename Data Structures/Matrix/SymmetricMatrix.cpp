#include<bits/stdc++.h>

using namespace std;

class SymmetricMatrix
{
    private:
    int n;
    int *A;

    public:

    SymmetricMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int element)
    {
        if(i >= j)
        {
            // Row Major Mapping
            A[i*(i-1)/2+j-1] = element;
        }
    }

    int get(int i, int j)
    {
        if(i >= j)
        {
            return A[i*(i-1)/2+j-1];
        }
        else if(i < j)
        {
            return A[j*(j-1)/2+i-1];
        }
    }

    void display()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i >= j)
                {
                    cout << A[i*(i-1)/2+j-1] << " ";
                }
                else if(i < j)
                {
                    cout << A[j*(j-1)/2+i-1] << " ";
                }
            }
            cout << endl;
        }
    }

    int getSize()
    {
        return n;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SymmetricMatrix sm = SymmetricMatrix(3);

    for(int i=1; i<=sm.getSize(); i++)
    {
        for(int j=1; j<=i; j++)
        {
            int x; cin >> x;
            sm.set(i,j,x);
        }
    }

    sm.display();

}