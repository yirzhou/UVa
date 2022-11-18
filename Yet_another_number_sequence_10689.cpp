#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 15000

int fibs[MAXN];

ii M[4] = { { 60, 10 }, { 300, 100 }, { 1500, 1000 }, { 15000, 10000 } };

void f()
{
    for (int i = 2; i < MAXN; ++i)
        fibs[i] = (fibs[i - 1] + fibs[i - 2]) % 10000;
}

int main()
{
    int t, a, b, n, m;

    cin >> t;
    while (t--) {
        fill(fibs, fibs + MAXN, 0LL);
        cin >> a >> b >> n >> m;
        fibs[0] = a, fibs[1] = b;
        f();

        int period = M[m - 1].first, divisor = M[m - 1].second;
        int res = fibs[n % period] % divisor;
        cout << res << endl;
    }
}