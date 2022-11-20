#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

int cnts[10];

void solve(int n)
{
    memset(cnts, 0, sizeof(cnts));
    vi v(1, 1);
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            x += i * v[j];
            v[j] = x % 10;
            x /= 10;
        }
        while (x) {
            v.pb(x % 10);
            x /= 10;
        }
    }

    for (auto& d : v)
        cnts[d]++;

    printf("%d! --", n);
    for (int i = 0; i < 10; ++i) {
        if (i == 0 || i == 5)
            printf("\n   (%d)", i);
        else
            printf("    (%d)", i);
        string s = to_string(cnts[i]);
        for (int i = 0; i < 5 - s.size(); ++i)
            printf(" ");
        printf("%d", cnts[i]);
    }
}

int main()
{
    int n;

    while (cin >> n && n) {
        solve(n);
        printf("\n");
    }
}