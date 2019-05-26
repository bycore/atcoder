#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
char s[N];
int cur1, cur2, ans;
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (s[1] == 'p')
        ans = -1;
    cur2 = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'p') {
            if (cur1 < cur2) {
                cur1++;
            } else
                ans--, cur2++;
        } else {
            if (cur1 < cur2) {
                cur1++;
                ans++;
            } else
                cur2++;
        }
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}