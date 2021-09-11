#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



class Graph{
    //adj list
    int vertices;
    unordered_map<string, list<pair<string,int>> > l;
public:

    Graph(){
        vertices = 0;
    }

    /** 
     * * adding an edge:
     * * takes 3 params: string x, string y, boolean bidirectional
     * * x & y are the values nothing more. bool bidirectional is a confirmation that they must be connected to each other rather than a single connection
    */
    void addEdge(string x, string y, bool isBidirectional, int weight){
        l[x].push_back(make_pair(y,weight));
        if(isBidirectional){
            l[y].push_back(make_pair(x,weight));
        }
        vertices++;
    }

    void printList(){
        for(auto p : l){
            string city = p.first;
            list<pair<string,int>> numbers = p.second;

            cout << city << "->";
            for(auto num : numbers){
                string dest = num.first;
                int distance = num.second;

                cout << dest << ": " << distance << "km. ";
            }
            cout << "\n";
        }
    }

    void journeyBFS(string start){
        cout << "BFS : ";
        int distance = 0;
        queue<string> q;
        set<string> visited;
        q.push(start);
        visited.insert(start);
        

        list<pair<string,int>>::iterator i;
        
        while(!q.empty()){
            string current = q.front();
            q.pop();
            cout << current << " ";

            for(i = l[current].begin(); i != l[current].end(); i++){
                if(!visited.count(i->first)){
                    visited.insert(i->first);
                    q.push(i->first);
                    distance += i->second;
                }
            }
        }

        cout << "\n| Distance travelled: " << distance << "\n";
    }

    void journeyDFS(string start){
        cout << "DFS : ";
        int distance = 0;
        stack<string> stk;
        set<string> visited;
        stk.push(start);
        visited.insert(start);
        

        list<pair<string,int>>::iterator i;
        
        while(!stk.empty()){
            string current = stk.top();
            stk.pop();
            cout << current << " ";

            for(i = l[current].begin(); i != l[current].end(); i++){
                if(!visited.count(i->first)){
                    visited.insert(i->first);
                    stk.push(i->first);
                    distance += i->second;
                }
            }
        }

        cout << "\n| Distance travelled: " << distance << "\n";
    }

    int getVertices(){
        return vertices;
    }
};




int main()
{
    fastio;

    Graph g;
    g.addEdge("Dhaka", "Sylhet", true, 50);
    g.addEdge("Dhaka", "Chittagong", true, 40);
    g.addEdge("Sylhet", "Chittagong", true, 30);
    g.addEdge("Chittagong", "Comilla", true, 20);
    g.addEdge("Comilla", "Mymenshing", true, 90);
    g.addEdge("Mymenshing", "Rajshahi", true, 20);

    //g.printList();

    cout << g.getVertices() << "\n";

    g.journeyBFS("Dhaka");
    g.journeyDFS("Dhaka");
    
}