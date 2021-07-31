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

const int mod = 1000000000 + 7;

int power(int x, int y, int MOD = mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}

int inverse(int n, int p) {
    return power(n, p - 2, p);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n,m;
        cin >> n>>m;
        int ar[n];
        int br[m];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
        }
        for (int i = 0; i < m; ++i) {
            cin>>br[i];
        }
        sort(br,br+m);
        int mini = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(br,br+m,ar[i]) - br;
            if(pos<m && br[pos]==ar[i]){
                mini = 0;
                break;
            }
            if(pos<m){
                mini = min(mini,abs(br[pos] - ar[i]));
            }
            if(pos>0){
                mini = min(mini,abs(br[pos-1] - ar[i]));
            }
        }
        cout<<mini;
        cout << "\n";
    }
}