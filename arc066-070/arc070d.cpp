#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> a;
ll solve()
{
    ll res = 0;
    cin >> N >> K;
    a.resize(N);
    for (auto& in : a)
        cin >> in;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = -1;
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (ll j = i; j < N; j++) {
            if (sum + a[j] < K) {
                sum += a[j];
                continue;
            }
            ans = max(ans, j);
        }
    }
    return res = N - ans - 1;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}