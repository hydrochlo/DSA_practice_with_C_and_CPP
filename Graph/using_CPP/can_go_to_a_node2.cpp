#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vl = vector<ll>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'

bool found = false;

void dfs(int node, vector<int> graph[], vector<bool> &visited){
    if(node == 3){
        found = true;
    }
    visited[node] = true;
    cout << node << " ";
    for(auto &child: graph[node]){
        if(!visited[child])
            dfs(child, graph, visited);
    }
}


void solve() {
    
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> graph[nodes + 1];
    vector<bool> isVisted(nodes+1, false);
    for(int i=1; i<=edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    // 5 to 3
    dfs(5, graph, isVisted);
    cout << endl;
    
    if(found){
        cout << "Possible.\n";
    } else {
        cout << "Not Possible.\n";
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}