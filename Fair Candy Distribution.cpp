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
class Pair{
public:
    int indices;
    int id;
    int pieces;
};
bool sortByValue(Pair p1,Pair p2){
    return p1.id<=p2.id;
}
bool sortByIndices(Pair p1,Pair p2){
    return p1.indices < p2.indices;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int n,k;
        cin >> n>>k;
        int miniValue = k/n;
        int remaining = k%n;
        Pair ar[n];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i].id;
            ar[i].indices = i;
            ar[i].pieces = miniValue;
        }
        sort(ar,ar+n,sortByValue);
        for (int i = 0; i < remaining; ++i) {
            ar[i].pieces+=1;
        }
        sort(ar,ar+n, sortByIndices);
        for (int i = 0; i < n; ++i) {
            cout<<ar[i].pieces<<"\n";
        }
    }
}