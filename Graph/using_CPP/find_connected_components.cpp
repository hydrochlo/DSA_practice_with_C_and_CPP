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


void dfs(int node, vector<int> graph[], vector<bool> &visited){
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

    int components = 0;
    for(int i=1; i<=nodes; i++){
        if(!isVisted[i]){
            // cout << i << endl;
            dfs(i, graph, isVisted);
            components++;
        }
    }

    cout << "Total components: " << components << endl;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}

/*

12 9
1 2
1 3
2 3
4 5
5 6
8 9
9 10
9 11
12 7

*/