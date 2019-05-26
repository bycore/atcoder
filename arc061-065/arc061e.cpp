#include <bits/stdc++.h>
using namespace std;
#define N 5000010
#define inf 0x3f3f3f3f
int head[N], cnt;
int d[N], vis[N], q[N];
int n, m;
struct node {
    int to, nxt, v;
} e[N];
void ins(int u, int v, int w)
{
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].v = w;
    head[u] = cnt;
}
map<pair<int, int>, int> mp;
int tot = 0;
int get_num(int x, int y)
{
    if (!mp.count(make_pair(x, y)))
        mp[make_pair(x, y)] = ++tot;
    return mp[make_pair(x, y)];
}
void spfa()
{
    for (int i = 1; i <= tot; i++)
        d[i] = inf;
    vis[1] = q[1] = 1;
    d[1] = 0;
    int l = 1, r = 2;
    while (l < r) {
        int u = q[l++];
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (d[v] > d[u] + e[i].v) {
                d[v] = d[u] + e[i].v;
                if (!vis[v])
                    vis[v] = 1, q[r++] = v;
            }
        }
    }
    if (d[n] == inf)
        puts("-1");
    else
        printf("%d\n", d[n] / 2);
}
int main()
{
    scanf("%d%d", &n, &m);
    tot = n;
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        int n1 = get_num(x, c), n2 = get_num(y, c);
        ins(x, n1, 1);
        ins(n1, x, 1);
        ins(n1, y, 1);
        ins(y, n1, 1);
        ins(n1, n2, 0);
        ins(n2, n1, 0);
    }
    spfa();
}
