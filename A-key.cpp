#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int N = 1e5 + 5;

vector <pair<int, string>> adj[N];
int n, m, u, v;
string s;

int main() {
    // please don't change the code template

    // fast I/O setup
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> s;
        adj[v].push_back({u, s});
    }

    int counter = 0;
    for(int i = 1; i <= n; i++) {
        int locked = 0;
        for(auto u : adj[i]) {
            if(u.second == "locked")
                locked++;
        }
        if(locked > adj[i].size() - locked)
            counter++;
    }
    cout << counter << endl;

    // your code here

    // to write a line to output
    // std::cout << "your output here\n";

    std::cout.flush();
    return 0;
}
