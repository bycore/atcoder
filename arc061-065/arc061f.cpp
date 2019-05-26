#include <bits/stdc++.h>
using namespace std;
#define N 5010
#define ll long long
const int mod = 1e9 + 7;
int n, m, k;
ll fac[N], ifac[N];
ll power(ll a, ll b)
{
    ll base = a, ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}
ll mul(ll x, ll y)
{
    return (1ll * x * y) % mod;
}
ll inv(ll x)
{
    return power(x, mod - 2) % mod;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);

    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = mul(fac[i - 1], i);
    for (int i = 0; i < N; i++)
        ifac[i] = inv(fac[i]);

    ll ans = 0, sum = n + k + m;
    for (int i = n; i <= sum; i++) { // 取出n张A牌
        for (int j = 0; j <= m; j++) { //B牌数量
            int C = i - n - j; //C牌数量
            if (C < 0 || C > k)
                continue;
            ll tmp = mul(fac[i - 1], mul(ifac[n - 1], mul(ifac[j], ifac[C])));
            tmp = mul(tmp, power(3, sum - i));
            ans = (ans + tmp) % mod;
        }
    }
    printf("%lld\n", ans);
}