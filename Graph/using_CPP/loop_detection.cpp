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

int loop = 0;

void dfs(int node, int parent, vector<int> graph[], vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";
    for(auto &child: graph[node]){
        if(child!=parent && visited[child]){
            cout << node << "->" << child << endl;
            cout << "There is a cycle.";
            loop++;
        } else if(!visited[child]){
            dfs(child, node, graph, visited);
        }

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

    dfs(1, -1, graph, isVisted);
    cout << "There are " << loop << " loops." << endl;

}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}
/*
input:
7 8
1 2
1 3
2 3
2 4
4 5
5 6
5 7
6 7
output: 1

input:
3 3
1 2
2 3
1 3
*/