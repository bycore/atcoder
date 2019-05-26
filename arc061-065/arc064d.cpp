#include <bits/stdc++.h>
using namespace std;
#define N 100010
char arr[N];
int main()
{
    int cnt = 0;
    scanf("%s", arr + 1);
    int n = strlen(arr + 1), k = n & 1;
    puts(abs(k - (arr[n] == arr[1])) & 1 ? "First" : "Second");
}
