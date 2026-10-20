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

int nodes, edges;

void dfs(int curr, int parent, vector<vector<int>> &t){
    cout << curr << " ";
    for(int i=1; i<=nodes; i++){
        if(t[curr][i] == 1){
            if(i != parent){
                dfs(i, curr, t);
            }
        }   
    }
}

void solve() {
    

    cin >> nodes >> edges;

    vector<vector<int>> tree(nodes+1, vector<int> (nodes+1, 0));

    for(int i=1; i<=edges; i++){
        int u, v;
        cin >> u >> v;
        tree[u][v] = 1;
        tree[v][u] = 1;
    }
    dfs(1, -1, tree);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}