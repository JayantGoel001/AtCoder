#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int unsigned long long int
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
        int n;
        cin >> n;
        int a,b;
        cin>>a>>b;
        int ar[n];
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
            mp[ar[i]]++;
        }
        sort(ar,ar+n,greater<int>());
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < a; ++i) {
            sum+=ar[i];
            v.push_back(ar[i]);
        }
        double avg = (double)sum/a;
        for (int i = a; i <b; ++i) {
            int low = lower_bound(ar+i,ar+n,avg) - ar;
            if (low!=n){
                sum+=ar[i];
                v.push_back(ar[i]);
                avg = (double)sum/v.size();
            }
        }
        int prod = 1;
        for (int i = 0; i < v.size(); ++i) {
            prod *= mp[ar[i]];
        }
        cout<<fixed<<setprecision(6)<<avg<<"\n";
        cout<<prod;
        cout << "\n";
    }
}