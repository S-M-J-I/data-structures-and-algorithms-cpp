#include <bits/stdc++.h>

using namespace std;

class Toepliz
{
private:
    int n;
    int *A;

public:
    Toepliz(int n)
    {
        this->n = n;
        A = new int[n + n - 1];
    }

    void set(int i, int j, int element)
    {
        if (i <= j)
        {
            A[j - i] = element;
        }
        else if (i > j)
        {
            A[n + i - j - 1] = element;
        }
    }

    int get(int i, int j)
    {
        if (i <= j)
        {
            return A[j - i];
        }
        else if (i > j)
        {
            return A[n + i - j - 1];
        }
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                {
                    cout << A[j - i] << " ";
                }
                else if (i > j)
                {
                    cout << A[n + i - j - 1] << " ";
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

    Toepliz tp = Toepliz(3);
    for(int i=1; i<=tp.getSize(); i++)
    {
        for(int j=1; j<=tp.getSize(); j++)
        {
            int x; cin >> x;
            tp.set(i,j,x);
        }
    }

    tp.display();
}