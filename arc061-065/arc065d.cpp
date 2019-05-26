#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int pre1[N], pre2[N];
int find(int x, int* pre)
{
    return pre[x] == x ? pre[x] : pre[x] = find(pre[x], pre);
}
int join(int x, int y, int* pre)
{
    int px = find(x, pre);
    int py = find(y, pre);
    if (px != py) {
        pre[px] = py;
    }
}
int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++)
        pre1[i] = i, pre2[i] = i;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        join(x, y, pre1);
    }
    for (int i = 1; i <= l; i++) {
        int x, y;
        cin >> x >> y;
        join(x, y, pre2);
    }
    for (int i = 1; i <= n; i++) {
        find(i, pre1);
        find(i, pre2);
    }
    map<pair<int ,int>,int> mp;
    for(int i=1;i<=n;i++){
        mp[make_pair(pre1[i],pre2[i])]++;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[make_pair(pre1[i],pre2[i])]<<" ";
    }
    cout<<endl;
    system("pause");
}