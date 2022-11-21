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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

bool solve(string& s, ll d)
{
    ll num = 0;
    for (auto& c : s) {
        num = num * 10 + c - '0';
        num %= d;
    }

    return num % d == 0;
}

int main()
{
    string s;

    getline(cin, s);
    int n = stoi(s);
    while (n--) {
        ll cnt, val, m = 1;
        getline(cin, s);
        cin >> cnt;
        while (cnt--) {
            cin >> val;
            m = lcm(m, val);
        }
        cout << s << " - ";
        cout << (solve(s, m) ? "Wonderful." : "Simple.") << endl;
        scanf("\n");
    }
}