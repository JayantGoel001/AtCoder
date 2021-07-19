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
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        int h,w,c;
        cin >> h>>w>>c;
        int **ar = new int*[h];
        for (int i = 0; i < h; ++i) {
            ar[i] = new int[w];
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin>>ar[i][j];
            }
        }
        int dp[h][w];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i==0 && j==0){
                    dp[i][j] = INT_MAX;
                } else if (i==0){
                    dp[i][j] = min(ar[i][j],dp[i][j-1] + c);
                } else if (j==0){
                    dp[i][j] = min(ar[i][j],dp[i-1][j] + c);
                } else{
                    dp[i][j] = min(ar[i][j],min(dp[i-1][j] + c,dp[i][j-1] + c));
                }
            }
        }
        int x[h][w];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                x[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i==0 && j==0){
                    x[i][j] = c + ar[i][j];
                } else if (i==0){
                    x[i][j] = dp[i][j-1] + c + ar[i][j];
                } else if (j==0){
                    x[i][j] = dp[i-1][j] + c + ar[i][j];
                } else{
                    x[i][j] = min(dp[i-1][j],dp[i][j-1]) + c + ar[i][j];
                }
            }
        }
        cout<<x[h-1][w-1];
        cout << "\n";
    }
}