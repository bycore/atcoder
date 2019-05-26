#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
    string S; cin >> S;
    int k=S.length();
    int tmp = 1;
    for(int i = 0; i < k-1;i++){
        if(S[i] != S[i+1]) tmp++;
    }
    cout << tmp-1 << endl;
	return 0;
}