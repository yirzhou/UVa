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

int main()
{
    ll B, P, M;
    string s;
    while (cin >> B >> P >> M) {
        if (M == 1)
            cout << 0 << endl;
        else {
            ll res = modpow<ll>(B, P, M);
            cout << res << endl;
        }

        getline(cin, s);
    }
}