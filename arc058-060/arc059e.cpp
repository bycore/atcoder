#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=410;
const ll mod = 1e9+7 ; 
ll a[N],b[N];
ll sum[N][N], l[N][N];
ll dp[N][N];
int main(){
    ll n,m;
    scanf("%lld%lld",&n, &m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=0; i<N; i++){
        l[i][0]=1;
        for(int j=1; j<N; j++){
            l[i][j]=(l[i][j-1]*i)%mod;
        }
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            sum[i][j]=(sum[i][j]+sum[i-1][j]+l[i][j])%mod;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]=((dp[i][j]%mod+(1ll*dp[i-1][j-k]*(sum[b[i]][k]-sum[a[i]-1][k]))%mod+mod)%mod+mod)%mod;
            }
        }
    }
    printf("%lld\n",(dp[n][m]+mod)%mod);
    //system("pause");
    return 0;
}