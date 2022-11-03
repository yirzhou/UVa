#include <bits/stdc++.h>

using namespace std;
int n, d, r;
int MS[100];
int ES[100];

int f()
{
    sort(MS, MS + n);
    sort(ES, ES + n);
    int l = 0, h = n - 1, ans = 0;
    while (l < n) {
        int t = MS[l] + ES[h];
        if (t - d > 0) {
            ans += (t - d) * r;
        }
        l++;
        h--;
    }
    return ans;
}

int main()
{
    while (scanf("%d %d %d", &n, &d, &r) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &MS[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ES[i]);
        }
        int res = f();
        printf("%d\n", res);
    }
}
