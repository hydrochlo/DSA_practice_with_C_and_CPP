#include <bits/stdc++.h>
using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    set<pair<int, int>> adjList[nodes+1];
    while(edges--){
        int u, v, wt;
        cin >> u >> v >> wt;

        adjList[u].insert({v, wt});
        adjList[v].insert({u, wt});
    }

    for(int i=1; i<=nodes; i++){
        cout << i << " : ";
        for(const auto &it: adjList[i]){
            cout << "[ node: " << it.first << ", cost: " << it.second << "] ";
        }
        cout << endl;
    }

    return 0;
}