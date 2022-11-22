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

int f(int L, int Z, int I, int M)
{
    return (Z * L + I) % M;
}

ii floyd_cf(int x0, int Z, int I, int M)
{
    int tortoise = f(x0, Z, I, M), hare = f(f(x0, Z, I, M), Z, I, M);
    while (tortoise != hare)
        tortoise = f(tortoise, Z, I, M), hare = f(f(hare, Z, I, M), Z, I, M);
    int mu = 0;
    hare = x0;
    while (tortoise != hare)
        tortoise = f(tortoise, Z, I, M), hare = f(hare, Z, I, M), mu++;

    int lambda = 1;
    hare = f(tortoise, Z, I, M);
    while (tortoise != hare)
        hare = f(hare, Z, I, M), lambda++;
    return { mu, lambda };
}

int main()
{
    int Z, I, M, L;
    int caseno = 1;
    while (cin >> Z >> I >> M >> L && (Z || I || M || L)) {
        ii res = floyd_cf(L, Z, I, M);
        printf("Case %d: %d\n", caseno++, res.se);
    }
}