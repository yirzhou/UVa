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

#define MOD 131071

template <typename T>
T modpow(T base, T exp, T M)
{
    base %= M;
    T result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return result;
}

bool solve(string& s)
{
    ll res = 0, p = 0;

    for (int i = s.size() - 2; i >= 0; --i) {
        if (s[i] == '1') {
            res = (res + modpow<ll>(2, p, MOD)) % MOD;
        }
        p++;
    }
    return (res % MOD) == 0;
}

int main()
{
    string s, line;
    while (getline(cin, line) && line.size()) {
        if (line != "\n")
            s += line;
        if (s.back() == '#') {
            printf(solve(s) ? "YES" : "NO");
            puts("");
            s.clear();
        }
    }
}