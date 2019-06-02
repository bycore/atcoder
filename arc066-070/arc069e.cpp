#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
void solve()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> xa = a;
    sort(xa.begin(), xa.end());
    xa.erase(unique(xa.begin(), xa.end()), xa.end());
    for (int i = 0; i < N; i++) {
        a[i] = (ll)(lower_bound(xa.begin(), xa.end(), a[i]) - xa.begin());
    }
    vector<ll> imos(xa.size() + 1);
    for (int i = 0; i < N; i++) {
        imos[0]++;
        imos[a[i] + 1]--;
    }
    for (int i = 0; i < xa.size(); i++)
        imos[i + 1] += imos[i];
    vector<ll> ans(N);
    vector<pll> p;
    for (int i = 0; i < N; i++) {
        if (p.empty())
            p.push_back({ a[0], i });
        if (p[p.size() - 1].first < a[i])
            p.push_back({ a[i], i });
    }
    ll sum = 0;
    ll idx = 0;
    for (int i = 0; i < xa.size(); i++) {
        if (i == 0) {
            sum += xa[i] * imos[i];
        } else {
            sum += (xa[i] - xa[i - 1]) * imos[i];
        }

        if (p[idx].first == i) {
            ans[p[idx].second] = sum;
            sum = 0;
            idx++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}