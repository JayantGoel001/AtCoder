#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int power(int x, int y, int MOD = INF) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2) % MOD) % MOD;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n,q;
        cin >> n>>q;
        vector<int> adj[n];
        for (int i = 0; i < n - 1; ++i) {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> Q;
        vector<bool> visited(n, false);
        vector<int> distance(n,0);

        visited[0] = true;
        Q.push(0);

        while (!Q.empty()){
            int front = Q.front();
            Q.pop();
            for (int i = 0; i < adj[front].size(); ++i) {
                if (!visited[adj[front][i]]){
                    distance[adj[front][i]] = distance[front]+1;
                    Q.push(adj[front][i]);
                    visited[adj[front][i]] = true;
                }
            }
        }
        while (q--){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if (abs(distance[y] - distance[x]) %2==0){
                cout<<"Town";
            } else{
                cout<<"Road";
            }
            cout<<"\n";
        }
    }
}