#include <bits/stdc++.h>
#include "Queues.h"

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

void BFS(int G[][7], int start, int n)
{
    Queue q = Queue();
    int i = start; // start of a traversal
    int visited[7] = {0}; // visited array
    
    cout << i << " ";
    visited[i] = 1; // set visited to one
    q.enqueue(i); // enqueue i

    while(!q.isEmpty())
    {
        i = q.dequeue();
        for(int j=1; j<n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.enqueue(j);
            }
        }
    }

}

void DFS(int G[][7], int start, int n)
{
    Stack stk = Stack();
    int i = start;
    int visited[7] = {0};

    cout << i << " ";
    visited[i] = 1;
    stk.push(i);

    while(!stk.isEmpty())
    {
        i = stk.pop();
        for(int j=1; j<n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                stk.push(j);
            }
        }
    }
}

void recursiveDFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int i = start;

    if(visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for(int j=1; j<n; j++)
        {
            if(G[start][j] == 1  && visited[j] == 0)
            {
                recursiveDFS(G,j,n);
            }
        }
    }
}


int main()
{
    fastio;
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    
    cout << "BFS: ";
    BFS(G,1,7);
    cout << "\n";

    cout << "DFS: ";
    DFS(G,1,7);
    cout << "\n";

    cout << "DFS: ";
    recursiveDFS(G,1,7);
    
}
