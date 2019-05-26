#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];
    map<pll, ll> mp;
    for (int i = 0; i < N; i++) {
        for (int j = -2; j <= 0; j++) {
            for (int k = -2; k <= 0; k++) {
                ll nx = a[i] + j, ny = b[i] + k;
                if (nx <= 0 || nx >= H - 1 || ny <= 0 || ny >= W - 1)
                    continue;
                mp[pll(nx, ny)]++;
            }
        }
    }
    ll ans[10] = { 0 };
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans[it->second]++;
        //cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    ll sum = (H - 2) * (W - 2);
    for (auto v : ans) {
        sum -= v;
    }
    ans[0] += sum;
    for (auto v : ans) {
        cout << v << endl;
    }
    return 0;
}