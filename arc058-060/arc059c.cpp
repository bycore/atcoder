#include<bits/stdc++.h>
using namespace std;
const int N=1e2+50;
int arr[N];
int main(){
    int n;scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    int temp1=sum/n;
    int temp2=sum/n+1;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;i++){
        ans1+=(arr[i]-temp1)*(arr[i]-temp1);
        ans2+=(arr[i]-temp2)*(arr[i]-temp2);
    }
    printf("%d\n",min(ans1,ans2));
    //system("pause");
}