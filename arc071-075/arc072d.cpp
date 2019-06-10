#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll X, Y;
    cin >> X >> Y;
    if (abs(X - Y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
}