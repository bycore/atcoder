#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
const int mod=1e9+7;
ll n;ll dp[N],m;
int main(){
    scanf("%lld",&n);
    dp[n]=n;m=n-1;
    for(int i=n-1;i;i--){
        dp[i]=(1ll*(n-1)*(n-1))%mod;
        dp[i]=(dp[i]+dp[i+1])%mod;
        dp[i]=(dp[i]+m)%mod;
        m+=((i+2>n?1:dp[i+2])-1)%mod;
    }
    printf("%lld\n",dp[1]%mod);
    //system("pause");
}