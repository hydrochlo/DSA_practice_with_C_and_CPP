#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adjList[nodes+1];
    while(edges--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=nodes; i++){
        cout << i << " : ";
        for(const auto &nei: adjList[i]){
            cout << nei << " ";
        }
        cout << endl;
    }
}