#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll b,ll n){
    return n<b ? n : fun( b , n / b ) + n % b;
}
int main(){
    ll n,s;
    scanf("%lld%lld",&n,&s);
    if( s > n ) 
        return puts( "-1" ) , 0 ;
    if( s == n ) 
        return printf("%lld\n",n+1),0;
    ll m=sqrt(n);
    for(ll i=2; i<=m; i++){
        if(fun(i,n)==s){
            printf("%lld\n",i);
            return 0;
        }
    }
    ll ans=1e11;
    ll ns=n-s;
    for(ll i=1;i*i<=ns;i++){
        if((ns)%i==0){
            ll b=(ns)/i+1;
            if(fun(b,n)==s){
                ans=min(ans,b);
            }
            if(fun(i+1,n)==s){
                ans=min(ans,b);
            }
        }
    }
    printf("%lld\n",ans!=1e11?ans:-1);
    return 0;
}