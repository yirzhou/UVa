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

int cnt[10] = { 0 };

ll convert(string& s)
{
    ll num = 0;
    for (auto& c : s)
        num = num * 10 + c - '0';
    return num;
}

pair<ll, ll> solve(string& s)
{
    memset(cnt, 0, sizeof cnt);
    for (auto& c : s)
        cnt[c - '0']++;

    ll mind, maxd;
    for (int i = 1; i <= 9; ++i) {
        if (cnt[i]) {
            mind = i;
            break;
        }
    }

    for (int i = 9; i >= 1; --i) {
        if (cnt[i]) {
            maxd = i;
            break;
        }
    }

    ll mins = mind, maxs = 0;
    cnt[mind]--;

    for (int j = 0; j < cnt[0]; ++j)
        mins *= 10;

    for (int i = mind; i <= 9; ++i) {
        for (int j = 0; j < cnt[i]; ++j)
            mins = mins * 10 + i;
    }

    cnt[mind]++;

    for (int i = maxd; i >= 0; --i) {
        for (int j = 0; j < cnt[i]; ++j) {
            maxs = maxs * 10 + i;
        }
    }

    return { mins, maxs };
}

int main()
{
    string s;
    while (getline(cin, s) && s.size()) {
        if (s == "0") {
            printf("0 - 0 = 0 = 9 * 0\n");
            continue;
        }
        pair<ll, ll> res = solve(s);
        ll diff = res.second - res.first;
        ll q = diff / 9LL;
        printf("%lld - %lld = %lld = %lld * %lld\n", res.second, res.first, diff, 9LL, q);
    }
}