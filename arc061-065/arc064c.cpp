#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    for (auto& in : a)
        cin >> in;
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
        if (a[i - 1] > x) {
            ans += a[i - 1] - x;
            a[i - 1] = x;
        }
        ll tmp = a[i] + a[i - 1];
        if (tmp > x) {
            ans += tmp - x;
            a[i] -= tmp - x;
        }
    }
    cout << ans << endl;
    return 0;
}