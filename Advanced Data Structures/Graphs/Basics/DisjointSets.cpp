#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

class DisjointSet
{
private:
    /**
     * Take a rank array for Union
     * parent is the main array
     * n is the num of elements in the set
    */
    int *rank, *parent, n;

public:
    /* Calling the constructor will declare the arrays and the set */
    DisjointSet(int n)
    {
        this->n = n;
        this->parent = new int[n];
        this->rank = new int[n];
        makeset();
    }

    void makeset()
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    /** FIND */
    int Find(int i)
    {
        // if parent[i] equals i
        if (parent[i] == i)
        {
            // return
            return parent[i];
        }
        else
        {
            // find representative of the set
            int result = Find(parent[i]);
            // cache it by moving i's node under the representative 
            parent[i] = result;
            return result;
        }
    }

    void Union(int i, int j)
    {
        // take the representatives of the set
        int iRep = Find(i);
        int jRep = Find(j);

        // if reps are equal, return
        if(iRep == jRep)
        {
            return;
        }

        // get the rank of the representatives
        int iRank = rank[iRep];
        int jRank = rank[jRep];

        
        if(iRank < jRank)
        {
            parent[iRep] = jRep;
        }
        else if (jRank < iRank)
        {
            parent[jRep] = iRep;
        }
        else
        {
            parent[jRep] = iRep;
            iRank++;
        }
    }
};

int main()
{
    DisjointSet djset(5);
    djset.Union(0, 2);
    djset.Union(4, 2);
    djset.Union(3, 1);
    if (djset.Find(4) == djset.Find(0))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    if (djset.Find(1) == djset.Find(0))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}