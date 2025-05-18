#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int s, vector<vector<pair<int, string>>> &adj, vector<bool> &visited)
{
    if (visited[s])
    {
        return;
    }
    visited[s] = true; // starting node s
    // process node
    for (auto u : adj[s])
        if (u.second == "safe" || u.second == "locked")
            dfs(u.first, adj, visited);
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, string>>> adj(n); // adjacency lists

    vector<bool> visited(n);
    // please don't change the code template

    // fast I/O setup
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        string s;
        cin >> u >> v >> s;
        adj[u - 1].push_back({v - 1, s});
    }

    dfs(0, adj, visited);

    bool isWayToAll = true;
    for (auto x : visited)
    {
        if (!x)
        {
            isWayToAll = false;
            break;
        }
    }
    if (isWayToAll)
        cout << "Connected" << endl;
    else
        cout << "Disconnected" << endl;

    // your code here

    // to write a line to output
    // std::cout << "your output here\n";

    std::cout.flush();
    return 0;
}