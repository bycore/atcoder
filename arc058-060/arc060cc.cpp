#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
ll f[maxn][35];
int main()
{
    int n, step, q, i, j, p;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    scanf("%d%d", &step, &q);
    for (i = 0; i < n; i++) {
        p = upper_bound(a, a + n, a[i] + step) - a;
        f[i + 1][0] = p;
    }
    for (int j = 1; j <= 30; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        if (l > r)
            swap(l, r);
        ll ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (f[l][i] < r) {
                ans += (ll)(1 << i);
                l = f[l][i];
            }
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}
/*
9
1 3 6 13 15 18 19 29 31
10
4
1 8
7 3
6 7
8 5

4
2
1
2
*/