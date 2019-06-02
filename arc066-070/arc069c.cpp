#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500000 + 5; 
ll n, m;
int main()
{
    scanf("%lld%lld", &n, &m);
    if (2 * n >= m) {
        cout << min(n, m / 2) << endl;
    } else {
        ll cha = m - 2 * n;
        cout << n + cha / 4 << endl;
    }
    return 0;
}