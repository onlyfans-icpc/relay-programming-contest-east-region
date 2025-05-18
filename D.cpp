#include <bits/stdc++.h>
using namespace std;

class DirectedCycle
{
    vector<vector<pair<int, string>>> graph; // index:node i,vec: The next node of this node
    vector<bool> visited;
    vector<int> edgeTo; // edgeTo[v]=w means w->v,Being used for backtracking paths
    vector<int> cycle;  // store cycle path
    vector<vector<int>> cycles;
    vector<bool> onStack; // All vertices on the stack during dfs
public:
    DirectedCycle(vector<vector<pair<int, string>>> g, int n)
    {
        graph = g;
        visited.resize(n);
        edgeTo.resize(n);
        onStack.resize(n);
        for (int i = 0; i < n; i++)
            DFS(i);
    }
    void DFS(int v)
    {
        visited[v] = true;
        onStack[v] = true; // add to stack
        for (auto item : graph[v])
        {
            if (HasCycle())
                return;
            if (!visited[item.first] && item.second == "loop")
            {
                edgeTo[item.first] = v;
                DFS(item.first);
            }
            else if (onStack[item.first])
            {
                cycle = vector<int>();
                for (int x = v; x != item.first; x = edgeTo[x])
                    cycle.push_back(x);
                cycle.push_back(item.first);
                cycles.push_back(cycle);
                cycle.clear();
            }
        }
        onStack[v] = false; // remove from the stack
    }
    bool HasCycle()
    {
        return !cycle.empty();
    }
    vector<vector<int>> CyclePath()
    {
        return cycles;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, string>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        string s;
        cin >> s;
        adj[u - 1].push_back({v - 1, s});
    }

    DirectedCycle geraf = DirectedCycle(adj, n);

    auto pp = geraf.CyclePath();
    cout << pp.size() << endl;
}