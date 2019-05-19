#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int flag=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            flag=1;
            break;
        }
        else if(i<s.size()-2&&s[i]==s[i+2]){
            cout<<i+1<<" "<<i+3<<endl;
            flag=1;
            break;
        }
    }
    if(!flag)
    cout<<-1<<" "<<-1<<endl;
    return 0;
}