#include<bits/stdc++.h>
#define int long long int
#define INF 1e18
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        int sum;
        cin>>sum;
        int n = ceil((-1 + sqrt(1+8*sum))/2);
        cout<<n<<"\n";
    }
}