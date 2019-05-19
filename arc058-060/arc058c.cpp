#include<bits/stdc++.h>
using namespace std;
int arr[15];
int N,k;int ans=0;
int check(int x){
    while(x){
        if(arr[x%10]==1){
            return 0;
        }
        x/=10;
    }
    return 1;
}
int main(){
    for(int i=0;i<15;i++){
        arr[i]=0;
    }
    scanf("%d%d",&N,&k);
    for(int i=0;i<k;i++){
        int temp;
        scanf("%d",&temp);
        arr[temp]=1;
    }
    for(int i=N;i<=100010;i++){
        if(check(i)){
            printf("%d\n",i);
            //system("pause");
            return 0;
        }
    }
}