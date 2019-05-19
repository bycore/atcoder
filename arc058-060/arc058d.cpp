#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
const ll mod=1e9+7;
ll f[N],n,m,A,B;
ll powmod(ll x,ll n){
    ll s=1;
    while(n){
        if(n&1)
            s=(s*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return s;
}
ll C(ll n,ll m){
    ll a=f[n];
    ll b=(f[m]*f[n-m])%mod;
    return (a*powmod(b,mod-2))%mod;
}
int main(){
    f[0]=1;
    for(ll i=1;i<N;i++)
        f[i]=(f[i-1]*i)%mod;
    while(cin>>n>>m>>A>>B){
        ll res=0;
        for(ll i=B+1;i<=m;i++){
            ll tmp=(C(i-1+n-A-1,n-A-1)*C(m-i+A-1,m-i))%mod;
            res=(res+tmp)%mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
/*
2 3 1 1
2
*/