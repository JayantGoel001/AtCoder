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
        string str;
        cin>>str;
        int x1,x2,x3,x4;
        x1 = (int)str[0] - 48;
        x2 = (int)str[1] - 48;
        x3 = (int)str[2] - 48;
        x4 = (int)str[3] - 48;
        if(x1 == x2 && x2 == x3 && x3 == x4 && x1 == x4){
            cout<<"Weak";
        } else if( (x1+1)%10 ==x2 && (x2+1)%10==x3 && (x3+1)%10==x4){
            cout<<"Weak";
        } else{
            cout<<"Strong";
        }

        cout << "\n";
    }
}