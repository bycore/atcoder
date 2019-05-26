#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
#define ll long long
int n, t;
int a[N];
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0, mx = 0;
    int tot = 0;
    for (int i = n; i; i--) {
        mx = max(a[i], mx);
        ans = max(mx - a[i], ans);
    }
    mx = 0;
    for (int i = n; i; i--) {
        mx = max(a[i], mx);
        if (mx - a[i] == ans)
            tot++;
    }
    printf("%d\n", tot);
    return 0;
}