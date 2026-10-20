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

void fillWithFalse(vector<bool> &visited){
    int sz = visited.size();
    for(int i=1; i<sz; i++){
        visited[i] = false;
    }
}

void dfs(int node, vector<int> graph[], vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";
    for(auto &child: graph[node]){
        if(visited[child]){
            cout << node << "->" << child << endl;
            cout << "There is a cycle." << endl;
        } else if(!visited[child]){
            dfs(child, graph, visited);
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
    }

    dfs(6, graph, isVisted);


    cout << "\n----------------\n";
    for(int i=1; i<=6; i++){
        fillWithFalse(isVisted);
        dfs(i, graph, isVisted);
        cout << endl;
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}
/*
input:
4 4
4 3
3 4
3 2
2 1

input:
6 6
4 3
3 4
3 2
2 1
6 5
5 4
*/