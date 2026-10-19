#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph(){
        for(int i=0; i<V; i++){
            cout << i << " : ";
            for(int nei: l[i]){
                cout << nei << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    Graph g(edges);
    while(edges--){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printGraph();
}