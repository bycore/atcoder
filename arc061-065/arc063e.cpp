#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 0x3f3f3f3f
int n, K, d[N];
int head[N << 1], cnt, vis[N];
struct edge {
    int to, nxt;
} e[N << 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void ins(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int main()
{
    for (int i = 0; i < N; i++)
        d[i] = inf;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        ins(u, v);
        ins(v, u);
    }
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        int p, v;
        scanf("%d%d", &v, &p);
        d[v] = p;
        q.push(make_pair(p, v));
    }
    while (!q.empty()) {
        int u = q.top().second, val = q.top().first;
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (d[v] == inf)
                d[v] = val + 1, q.push(make_pair(d[v], v));
            if (abs(d[v] - d[u]) != 1) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        printf("%d\n", d[i]);
    }
    return 0;
}