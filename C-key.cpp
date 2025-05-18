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

    int counter = 0;
    for(int u = 1; u <= n; u++) {
        for(auto v : adj[u]) {
            if(abs(u - v.first) == 1 && v.second == "safe")
                counter++;
        }
    }
    cout << counter << endl;

    std::cout.flush();
    return 0;
}
