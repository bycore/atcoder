#include <bits/stdc++.h>
using namespace std;
int x;
int main()
{
    scanf("%d", &x);
    int sum = 0;
    for (int i = 1;; i++) {
        sum += i;
        if (sum >= x) {
            printf("%d\n", i);
            return 0;
        }
    }
}