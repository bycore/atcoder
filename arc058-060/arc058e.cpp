#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int dp[50][1<<17];
int ans=1;
ll S,fow;
int main(){
    int n;scanf("%d",&n);
    int x,y,z;scanf("%d%d%d",&x,&y,&z);
    for(int i=0;i<n;i++){
        ans=1ll*ans*10%mod;
    }
    S=(1<<x+y+z)-1;
    fow=(1<<x-1)|(1<<x+y-1)|(1<<x+y+z-1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=S;j++){
            for(int k=1;k<=10;k++){
                int T=(j<<k)|(1<<k-1);
                T&=S;
                if((T&fow)!=fow)
                    dp[i][T]=(dp[i][T]+dp[i-1][j])%mod;
            }
        }
    }
    for(int i=0;i<=S;i++){
        ans=(ans-dp[n][i]+mod)%mod;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}