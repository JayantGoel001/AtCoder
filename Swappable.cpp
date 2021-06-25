#include<bits/stdc++.h>
#define int long long int
#define INF 1e18
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
        }
        int count = 0;
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            count += (n-i-1);
            if (mp.count(ar[i])!=0){
                count -= mp[ar[i]];
            }
            mp[ar[i]]++;
        }
        cout<<count<<"\n";
    }
}