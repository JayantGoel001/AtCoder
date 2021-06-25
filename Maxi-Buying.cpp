#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        double n;
        cin>>n;
        int x = floor(1.08*n);
        if(x==206){
            cout<<"so-so\n";
        } else if (x<206){
            cout<<"Yay!\n";
        } else{
            cout<<":(\n";
        }
    }
}