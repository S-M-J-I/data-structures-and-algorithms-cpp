#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

class Edge
{
public:
    int src, dest;
};

class Graph
{

public:
    // V-> num of vertices
    // E-> num of edges
    int V, E;
    Edge *edges;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;

    graph->edges = new Edge[graph->E * sizeof(Edge)];

    return graph;
}

int Find(int parent[], int i)
{
    // if the val of i in parent array is -1, return it.
    if (parent[i] == -1)
    {
        return i;
    }
    else
    {
        // search for representative
        Find(parent, parent[i]);
    }

}

void Union(int parent[], int i, int j)
{
    // add j to i
    parent[i] = j;
}

bool isCycle(Graph *graph)
{
    // create and init parent array
    int *parent = new int[graph->V];
    for (int i = 0; i < graph->V; ++i)
    {
        parent[i] = -1;
    }

    // for all edges in the graph
    for (int i = 0; i < graph->E; ++i)
    {
        // find the representative node of src & dest
        int x = Find(parent, graph->edges[i].src);
        int y = Find(parent, graph->edges[i].dest);

        // if equal, it's a cycle
        if (x == y)
        {
            return true;
        }

        // else, join them
        Union(parent, x, y);
    }

    return false;
}

int main()
{
    Graph *g = createGraph(3,3);
    g->edges[0].src = 0;
    g->edges[0].dest = 1;

    g->edges[1].src = 1;
    g->edges[1].dest = 2;

    g->edges[2].src = 0;
    g->edges[2].dest = 2;

    if(isCycle(g))
    {
        cout << "There's a cycle\n";
    }
    else
    {
        cout << "There's no cycle\n";
    }
}

