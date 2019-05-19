#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, L, m;
int a[N], to[N];
int block, num, ans;
int nxt[N], val[N], belong[N];
int find(int x)
{
    int l = x + 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] - a[x] <= L)
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    scanf("%d%d", &L, &m);
    for (int i = 1; i < n; i++) {
        to[i] = find(i);
    }
    to[n] = n + 1;
    // for(int i=1;i<=n;i++){
    //     cout<<to[i]<<" ";
    // }
    block = sqrt(n);
    num = n / block;
    if (n % block)
        num++;
    for (int i = 1; i <= n; i++) {
        belong[i] = (i - 1) / block + 1;
    }
    for (int i = 1; i < n; i++) {
        int t = i, sp = 0;
        while (belong[t] == belong[i]) {
            t = to[t];
            sp++;
        }
        val[i] = sp;
        nxt[i] = t;
        if (i >= block * (num - 1) + 1) {
            val[i]--;
            nxt[i]--;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        ans = 0;
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y);
        while (belong[x] < belong[y]) {
            ans += val[x];
            x = nxt[x];
        }
        while (x < y) {
            x = to[x];
            ans++;
        }
        printf("%d\n", ans);
    }
    //system("pause");
}