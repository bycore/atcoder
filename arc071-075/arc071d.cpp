#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    for (auto& in : x) {
        cin >> in;
    }
    for (auto& in : y) {
        cin >> in;
    }
    ll x_sum = 0, y_sum = 0;
    for (int i = 0; i < n; i++) {
        (x_sum += (i * x[i] - (n - 1 - i) * x[i] + mod) % mod) %= mod;
    }
    for (int i = 0; i < m; i++) {
        (y_sum += (i * y[i] - (m - 1 - i) * y[i] + mod) % mod) %= mod;
    }
    ll ret = x_sum * y_sum % mod;
    cout << ret << endl;
    system("pause");
}