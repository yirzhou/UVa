#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define snl scanf("\n")
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

bool cmp(const char& a, const char& b)
{
    if (tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main()
{
    fastio;
    int N;
    cin >> N;
    string s;
    while (N--) {
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), cmp));
    }
}