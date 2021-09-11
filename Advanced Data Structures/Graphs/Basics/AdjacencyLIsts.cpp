#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

class Graph{
    int V;
    // array of list
    list<int> *l;

    public:

    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }

    // bidirectional connection
    void addEdge(int source, int destination, bool isBidirectional)
    {
        l[source].push_back(destination);
        if(isBidirectional){
            l[destination].push_back(source);
        }
    }


    void BFS(int root)
    {
        bool *visited = new bool[this->V];
        for(int i=0; i<this->V; i++){
            visited[i] = false;
        }

        queue<int> q;
        visited[root] = true;
        q.push(root);

        list<int>::iterator i;
        while(!q.empty()){
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for(i=l[currentVertex].begin(); i!=l[currentVertex].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }

    void DFS(int root)
    {
        bool *visited = new bool[this->V];
        for(int i=0; i<this->V; i++){
            visited[i] = false;
        }

        stack<int> stk;
        visited[root] = true;
        stk.push(root);

        list<int>::iterator i;
        while(!stk.empty()){
            int currentVertex = stk.top();
            stk.pop();
            cout << currentVertex << " ";

            for(i = l[currentVertex].begin(); i != l[currentVertex].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    stk.push(*i);
                }
            }
        }
    }

    vector<int> li;
    set<int> visited;
    void topologicalOrdering(int root){
        

    }

};


int main()
{
    Graph g(4);
    g.addEdge(0,1,true);
    g.addEdge(0,2,true);
    g.addEdge(2,3,true);
    g.addEdge(1,2,true);
    g.addEdge(3,0,true);


    g.BFS(0);
    cout << "\n";
    g.DFS(0);
    cout << "\n";

    Graph g1(4);
    g1.addEdge(0,1,false);
    g1.addEdge(0,2,false);
    g1.addEdge(1,3,false);
    g1.addEdge(2,3,false);
    g1.addEdge(3,0,false);

    for(int i = 0 ; i<4; i++){
        if(!g1.visited.count(i)){
            g1.topologicalOrdering(i);
        }
    }



}