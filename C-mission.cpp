#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


const int N = 1e5 + 5;
const int oo = 1e9 + 5;

vector <pair<int, string>> adj[N];
int n, m, u, v;
string s;
int dis[N];
queue<int> q;

int main() {
    // please don't change the code template

    // fast I/O setup
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> s;
        adj[u].push_back({v, s});
    }

    fill(dis, dis + n + 1, oo);
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(auto vv : adj[u])
            if(vv.second == "safe" && dis[u] + 1 < dis[vv.first]) {
                dis[vv.first] = dis[u] + 1;
                q.push(vv.first);
            }
    }
    if(dis[n] >= oo - 100)
        cout << "No Path\n";
    else
        cout << dis[n] << '\n';

    std::cout.flush();
    return 0;
}
