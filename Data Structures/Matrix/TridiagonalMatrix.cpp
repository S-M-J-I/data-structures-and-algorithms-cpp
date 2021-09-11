#include <bits/stdc++.h>

using namespace std;

class TridiagonalMatrix
{
private:
    int n;
    int *A;

public:
    TridiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3 * n - 2];
    }

    void set(int i, int j, int element)
    {
        if (i - j == 1)
        {
            A[i - 1] = element;
        }
        else if (i - j == 0)
        {
            A[(n - 1) + (i - 1)] = element;
        }
        else if (i - j == -1)
        {
            A[(2 * n - 1) + (i - 1)] = element;
        }
    }

    int get(int i, int j)
    {
        if (i - j == 1)
        {
            return A[i - 1];
        }
        else if (i - j == 0)
        {
            return A[(n - 1) + (i - 1)];
        }
        else if (i - j == -1)
        {
            return A[(2 * n - 1) + (i - 1)];
        }

        return 0;
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - j == 1)
                {
                    cout << A[i - 1] << " ";
                }
                else if (i - j == 0)
                {
                    cout << A[(n - 1) + (i - 1)] << " ";
                }
                else if (i - j == -1)
                {
                    cout << A[(2 * n - 1) + (i - 1)] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << "\n";
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

    TridiagonalMatrix tm = TridiagonalMatrix(5);

    for(int i=1; i<=tm.getSize(); i++)
    {
        for(int j=1; j<=tm.getSize(); j++)
        {
            int x; cin >> x;
            tm.set(i,j,x);
        }
    }

    tm.display();
}