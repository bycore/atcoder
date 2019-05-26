#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N;
    cin >> N;
    vector<long long> T, A;
    long long t = 1, a = 1;
    for (long long i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        T.push_back(x);
        A.push_back(y);
    }
    for (long long i = 0; i < N; i++) {
        long long temp = max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
        t = temp * T[i];
        a = temp * A[i];
    }
    cout << a + t << endl;
    //system("pause");
    return 0;
}