#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

int f(int a)
{
    return (a * a / 100) % 10000;
}

ii floyd_cf(int x0)
{
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare)
        tortoise = f(tortoise), hare = f(f(hare));
    int mu = 0;
    hare = x0;
    while (tortoise != hare)
        tortoise = f(tortoise), hare = f(hare), mu++;

    int lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare)
        hare = f(hare), lambda++;
    return { mu, lambda };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a0;
    while (cin >> a0 && a0) {
        ii res = floyd_cf(a0);
        cout << res.fi + res.se << endl;
    }
}