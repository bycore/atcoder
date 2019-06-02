#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    for (auto& in : X)
        cin >> in;
    ll res = 0;
    for (int i = 0; i < N - 1; i++) {
        res += min(A * (X[i + 1] - X[i]), B);
    }
    return res;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}