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
bool isOK(int n,const int *d){
    while (n!=0){
        if (d[n%10]!=0){
            return false;
        }
        n/=10;
    }
    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n,k;
        cin >> n>>k;
        int d[10];
        for (long long & i : d) {
            i=0;
        }
        for (int i = 0; i < k; ++i) {
            int x;
            cin>>x;
            d[x]=1;
        }
        while (!isOK(n,d)){
            n++;
        }
        cout<<n;
        cout << "\n";
    }
}