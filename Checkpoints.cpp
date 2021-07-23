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
    return b == 0 ? a : GCD(b, a % b);
}

int power(int x, int y, int MOD) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n,m;
        cin >> n>>m;
        pair<int,int> ar[n],br[m];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i].first>>ar[i].second;
        }
        for (int i = 0; i < m; ++i) {
            cin>>br[i].first>>br[i].second;
        }
        for (int i = 0; i < n; ++i) {
            int mini = INT_MAX;
            int index = -1;
            for (int j = 0; j < m; ++j) {
                int dist = abs(ar[i].first - br[j].first) + abs(ar[i].second - br[j].second);
                if (dist<mini){
                    mini = dist;
                    index = j;
                }
            }
            cout<<index+1<<"\n";
        }
    }
}