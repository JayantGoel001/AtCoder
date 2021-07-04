#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int unsigned long long int
#define double double_t
#define INF 1e19
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
    int MOD = power(10,9)+7;
    while (t--) {
        int n,m,k;
        cin >> n>>m>>k;
        n = n%MOD;
        int sum  = power(n,k,MOD);
        int prev = power(n-1,k,MOD);
        for (int i = 1; i <=m; ++i) {
            sum = (sum + prev + i)%MOD;
            cout<<sum<<"\n";
        }
        cout<<sum%MOD;
        cout << "\n";
    }
}