#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;


class Graph{

public:

    int vertices;
    list<int> *adjList;
    bool *visited;

    Graph(int vertices)
    {
        this->vertices = vertices;
        this->adjList = new list<int>[vertices];
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void BFS(int startVertex)
    {
        visited = new bool[this->vertices];
        for(int i=0; i<vertices; ++i)
        {
            visited[i] = false;
        }

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        list<int>::iterator i;

        while(!q.empty())
        {
            int actual = q.front();
            q.pop();
            cout << actual << " ";

            for(i=adjList[actual].begin() ; i != adjList[actual].end(); ++i)
            {
                if(!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }

    void DFS(int startVertex)
    {
        visited = new bool[vertices];
        for(int i=0; i<vertices; ++i)
        {
            visited[i] = false;
        }

        stack<int> stk;

        visited[startVertex] = true;
        stk.push(startVertex);

        list<int>::iterator i;
        while(!stk.empty())
        {
            int actual = stk.top();
            stk.pop();
            cout << actual << " ";

            for(i = adjList[actual].begin(); i != adjList[actual].end(); ++i)
            {
                if(!visited[*i])
                {
                    visited[*i] = true;
                    stk.push(*i);
                }
            }
        }
    }


};


int main()
{

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 4);
    g.addEdge(6, 4);
    

    g.BFS(0);
    cout << "\n";
    g.DFS(0);

}
