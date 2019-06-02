#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1e5 + 100;
int f[INF];
int main()
{
    int n, a;
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 2; i <= n; i++) {
        a = i;
        for (int j = 2; j <= a; j++) {
            while (a % j == 0) {
                f[j]++;
                a = a / j;
            }
        }
        if (a != 1)
            f[a]++;
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (f[i] != 0)
            ans = (ans * (f[i] + 1)) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}