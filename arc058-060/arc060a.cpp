#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=55;
int arr[N];
ll sum[N];
ll dp[N][N*N];
int main(){
    int n,A;
    sum[0]=0;
    scanf("%d%d",&n,&A);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        sum[i]=sum[i-1]+arr[i];
    }
    dp[0][0]=1;
    for(int k=1;k<=n;k++){
        for(int i=k;i>0;i--){
            for(int j=sum[k];j>=arr[k];j--){
                dp[i][j]+=dp[i-1][j-arr[k]];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i][i*A];
    }
    printf("%lld\n",ans);
    system("pause");
}
/*
4 8
7 9 8 9
5
*/