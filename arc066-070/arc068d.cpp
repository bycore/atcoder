#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto& in : A)
        cin >> in;
    const int MAX_N = 1e5 + 1;
    vector<ll> C(MAX_N, 0);
    for (auto& v : A)
        C[v]++;
    sort(C.begin(), C.end(), greater<ll>());
    for (int i = 0; i < (int)C.size(); i++) {
        if (C[i] >= 3) {
            if (C[i] % 2 == 1)
                C[i] = 1;
            else
                C[i] = 2;
        }
    }
    sort(C.begin(), C.end(), greater<ll>());
    for (int i = 0; i < (int)C.size(); i++)
        if (C[i] == 2) {
            C[i] = 1;
            C[i + 1]--;
        }
    cout << accumulate(C.begin(), C.end(), 0LL) << endl;
    return 0;
}