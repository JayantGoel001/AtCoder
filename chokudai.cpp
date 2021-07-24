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
const int MOD = (int)(1e9 + 7);
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;

    while (t--) {
        string str;
        cin >> str;
        string str2 = "chokudai";
        int **dp = new int*[str.length()+1];
        for (int i = 0; i <= str.length(); ++i) {
            dp[i] = new int[str2.length()+1];
        }
        for (int i = 0; i <=str.length(); ++i) {
            for (int j = 0; j <=str2.length(); ++j) {
                if (j==0){
                    dp[i][j] = 1;
                } else if (i==0){
                    dp[i][j] = 0;
                }else {
                    if (str[i - 1] == str2[j - 1]) {
                        dp[i][j] = (dp[i - 1][j]%MOD + dp[i - 1][j - 1]%MOD) % MOD;
                    } else {
                        dp[i][j] = dp[i - 1][j] % MOD;
                    }
                }
            }
        }
        cout<<dp[str.length()][str2.length()]%MOD;
        cout << "\n";
    }
}