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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int f(int x, int a, int b, int n)
{
    int sol = ((a % n) * (((1LL * x) * x) % n)) % n;
    sol = (sol + b) % n;
    return sol;
}
ii floyd_cf(int x0, int a, int b, int N)
{
    int tortoise = f(x0, a, b, N), hare = f(f(x0, a, b, N), a, b, N);
    while (tortoise != hare)
        tortoise = f(tortoise, a, b, N), hare = f(f(hare, a, b, N), a, b, N);
    int mu = 0;
    hare = x0;
    while (tortoise != hare)
        tortoise = f(tortoise, a, b, N), hare = f(hare, a, b, N), mu++;

    int lambda = 1;
    hare = f(tortoise, a, b, N);
    while (tortoise != hare)
        hare = f(hare, a, b, N), lambda++;
    return { mu, lambda };
}

int main()
{
    int N, a, b;
    while (cin >> N && N) {
        cin >> a >> b;
        pll res = floyd_cf(0, a, b, N);
        cout << N - res.se << endl;
    }
}