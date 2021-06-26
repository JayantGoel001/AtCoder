#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n = 1;
    cin >> n;
    pair<double_t,double_t> ar[n];
    for (int i = 0; i < n; ++i) {
        double_t t,l,r;
        cin>>t>>l>>r;
        if (t==2 || t==4){
            r-=0.5;
        }
        if (t==3 || t==4){
            l+=0.5;
        }
        ar[i] = make_pair(l,r);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ans += max(ar[i].first,ar[j].first) <= min(ar[i].second,ar[j].second);
        }
    }
    cout<<ans<<"\n";

}