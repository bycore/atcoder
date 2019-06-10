#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll n, vector<ll>& a, ll s, ll sum)
{
    ll ret = s;
    ll S = sum;
    for (int i = 1; i < n; i++) {
        if (S > 0) {
            if (S + a[i] < 0) {
                S += a[i];
            } else {
                ret += abs(S + a[i]) + 1;
                S = -1;
            }
        } else {
            if (S + a[i] > 0) {
                S += a[i];
            } else {
                ret += abs(S + a[i]) + 1;
                S = 1;
            }
        }
    }
    return ret;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& in : a)
        cin >> in;
    cout << min(
                calc(n, a, a[0] > 0 ? 0 : abs(a[0]) + 1, a[0] > 0 ? a[0] : 1),
                calc(n, a, a[0] < 0 ? 0 : abs(a[0]) + 1, a[0] < 0 ? a[0] : -1))
         << endl;
    return 0;
}