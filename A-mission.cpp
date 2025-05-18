#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


const int N = 1e5 + 5;

vector <pair<int, string>> adj[N];
int n, m, u, v;
string s;
vector<int> ans;

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

    // int counter = 0;
    for(int i = 1; i <= n; i++) {
        int locked = 0;
        int safe = 0;
        for(auto u : adj[i]) {
            if(u.second == "locked")
                locked++;
            else if(u.second == "safe")
                safe++;
        }
        if(locked > safe)
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    if(ans.size() == 0) {
        cout << "None\n";
    }
    else {
        for(auto x : ans) {
            cout << x << '\n';
        }
    }

    // cout << counter << endl;

    // your code here

    // to write a line to output
    // std::cout << "your output here\n";

    std::cout.flush();
    return 0;
}
