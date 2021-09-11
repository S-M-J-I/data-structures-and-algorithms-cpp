#include<bits/stdc++.h>

using namespace std;

class DiagonalMatrix
{
    private:
    int *A;
    int n;

    public:
    DiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int element)
    {
        if(i==j)
        {
            A[i-1] = element;
        }
    }

    int get(int i, int j)
    {
        if(i==j)
        {
            return A[i-1];
        }

        return 0;
    }

    void showDimension()
    {
        cout << n << "x" << n << "\n";
    }

    int getSize()
    {
        return this->n;
    }

    void display()
    {
        for(int i=1; i<=this->n; i++)
        {
            for(int j=1; j<=this->n; j++)
            {
                if(i==j)
                {
                    cout << A[i-1] << " ";
                }
                else
                {
                    cout << "0 ";
                } 
            }
            cout << "\n";
        }
        cout << "\n";
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    DiagonalMatrix dg = DiagonalMatrix(3);
    
    for(int i=1; i<=dg.getSize(); i++)
    {
        for(int j=1; j<=dg.getSize(); j++)
        {
            int x; cin >> x;
            dg.set(i,j,x);
        }
    }

    dg.display();
}