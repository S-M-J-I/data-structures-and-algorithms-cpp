#include<bits/stdc++.h>

using namespace std;

class LowerTriangleMatrix
{
    private:
    int n;
    int *A;

    public:
    
    LowerTriangleMatrix(int n)
    {
        this->n = n;
        A = new int[n*(n+1) / 2];
    }

    void set(int i, int j, int element)
    {
        if(i >= j)
        {
            // Row-Major Mapping
            A[i*(i-1)/2+j-1] = element;
        }
    }

    int get(int i, int j)
    {
        if(i >= j)
        {
            return A[i*(i-1)/2+j-1];
        }

        return 0;
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
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    int getDimension()
    {
        return n;
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LowerTriangleMatrix lt = LowerTriangleMatrix(3);
    for(int i=1; i<=lt.getDimension(); i++)
    {
        for(int j=1; j<=lt.getDimension(); j++)
        {
            int x; cin >> x;
            lt.set(i,j,x);
        }
    }

    lt.display();

}