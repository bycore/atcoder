#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
string S;
void dfs(int n, ll v, ll sum)
{
    if (S.length() == n) {
        sum += v;
        ans += sum;
        return;
    }
    ll next = v * 10 + S[n] - '0';
    dfs(n + 1, 0, sum + next);
    dfs(n + 1, next, sum);
}
int main()
{
    cin >> S;
    dfs(0, 0, 0);
    cout << ans / 2 << endl;
    return 0;
}