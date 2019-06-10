#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    int n;cin>>n;
    vector <string> S(n);
    for(auto &in:S){
        cin>>in;
    }
    vector<vector<int>> alpha(n,vector<int>(26,0));
    for(int x=0;x<n;x++){
        string & s=S[x];
        for(int i=0;i<(int)s.length();i++){
            alpha[x][s[i]-'a']++;
        }
    }
    string ans="";
    for(int i=0;i<26;i++){
        int minv=INF;
        for(int j=0;j<n;j++){
            minv=min(minv,alpha[j][i]);
        }
        ans+=string(minv,'a'+i);
    }
    cout<<ans<<endl;
    //system("pause");
}