#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
map<ll, ll> dp;
ll Dp(long long x)
{
    if (dp[x])
        return dp[x];
    else {
        return dp[x] = ((Dp(x / 2) + Dp((x - 1) / 2) + Dp((x - 2) / 2))) % mod;
    }
}
int main()
{
    dp[0] = 1;
    dp[1] = 2;
    long long n;
    cin >> n;
    cout << Dp(n);
    return 0;
}