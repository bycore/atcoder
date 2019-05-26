#include <bits/stdc++.h>
using namespace std;
int main() {
    string S; cin >> S;
    string s[4] = {"dream" , "dreamer", "erase" ,"eraser"};
    int at = (int)S.length();
    while(at > 0){
        bool f = false;
        for(int i = 0; i < 4;i++){
            if(at < s[i].length()) continue;
            string tmp = S.substr(at-s[i].length(),s[i].length());
            if(tmp == s[i]){
                f = true;
                at -= s[i].length();
                break;
            }
        }
        if(!f){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
	return 0;
}