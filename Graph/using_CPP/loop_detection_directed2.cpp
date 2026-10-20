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

bool loopFound = false;
vector<ll> lastVisited;

/*
1: 
2 : 1
3 : 4 2
*/

void dfs(int node, vector<int> graph[], vector<bool> &visited, vector<bool> &currVisited){
    visited[node] = true; // isVisited[1] = true; // isVisited[2] = true; // isVisited[3] = true; // isVisited[4] = true;
    currVisited[node] = true; // currVisited[1] = flase; // currVisited[2] = false; // currVisited[3] = false; // currVisited[4] = false;
    cout << node << " ";
    lastVisited.push_back(node); // lastVisited = {3 , 4, 2}
    for(auto &child: graph[node]){ // child = 2
        if(currVisited[child]){ // currVisited[2] = false
            loopFound = true;
            cout << node << " -> " << child << "\n";
            cout << "There is a cycle\n";
        }
        if(!visited[child]){ // visited[3] = true
            dfs(child, graph, visited, currVisited); // dfs(4, graph, visited, currVisited)
        }
    }
}


void solve() {
    
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> graph[nodes + 1];
    vector<bool> isVisited(nodes+1, false);
    vector<bool> currVisited(nodes+1, false);
    for(int i=1; i<=edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }

    for (int i = 1; i <= 3; i++) {
        if (!isVisited[i]) { // isVisited[1] = false;
            dfs(i, graph, isVisited, currVisited); // i=3
            cout << endl;
            if (loopFound)
                break;
            else {
                // Clear currently visited node
                for (auto& it : lastVisited) // lastVisited = {3, 4, 2}
                    currVisited[it] = false; // currVisited[2] = false;
                lastVisited.clear(); // lastVisited = {}
            }
        }
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