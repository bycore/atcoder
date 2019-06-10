#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    int Q;
    cin >> Q;
    vector<int> cusumS(S.length() + 1, 0), cusumT(T.length() + 1, 0);
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'A')
            cusumS[i + 1] = cusumS[i] + 2;
        else
            cusumS[i + 1] = cusumS[i] + 1;
    }
    for (int i = 0; i < T.length(); i++) {
        if (T[i] == 'A')
            cusumT[i + 1] = cusumT[i] + 2;
        else
            cusumT[i + 1] = cusumT[i] + 1;
    }
    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (abs((cusumS[b] - cusumS[a - 1]) - (cusumT[d] - cusumT[c - 1])) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    //system("pause");
}