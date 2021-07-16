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
int getResult(int avg,int *ar,int n){
    int output = 0;
    for (int i = 0; i < n; ++i) {
        output += power((ar[i]-avg),2);
    }
    return output;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        int ar[n];
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
            sum+=ar[i];
        }
        int avg1 = floor(sum/n);
        int avg2 = ceil(sum/n);

        cout<<min(getResult(avg1,ar,n), getResult(avg2,ar,n));
        cout << "\n";
    }
}