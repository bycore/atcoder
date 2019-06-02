#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define ll long long
int n;
int a[N];
int cnt[N];
ll ans = 0;
ll power(int a, int b)
{
    ll ans = 1, base = a;
    while (b) {
        if (b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), cnt[a[i]]++;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 2)
            return puts("0"), 0;
    }
    if (n & 1 && cnt[0] != 1)
        return puts("0"), 0;
    if (!(n & 1) && cnt[0])
        return puts("0"), 0;
    printf("%lld\n", power(2, n / 2));
}