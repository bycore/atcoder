#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
#define N 1500
int a[N];
int main()
{
    ll n;
    scanf("%lld", &n);
    if (n <= 6) {
        cout << 1 << endl;
    } else {
        ll ans = 0;
        ll x = n / 11;
        ll y = n % 11;
        ans += 2 * x;
        if (y <= 6 && y >= 1) {
            ans++;
        } else if (y > 6) {
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}
