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


void dfs(int curr_node, int parent, vector<int> graph[]){
    cout << curr_node << " ";
    for(auto &child: graph[curr_node]){
        if(child != parent)
            dfs(child, curr_node, graph);
    }
}


void solve() {
    
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> tree[nodes + 1];
    for(int i=1; i<=edges; i++){
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, -1, tree);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}