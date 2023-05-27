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

void counting_sort(string& s, vi& SA, vi& RA, vi& temp_SA, vi& temp_RA, int k)
{
    int n = s.size();
    int i, sum, maxi = max(300, n);

    vi c(maxi, 0);
    for (i = 0; i < n; ++i)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; ++i) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; ++i) {
        temp_SA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    }
    for (i = 0; i < n; ++i)
        SA[i] = temp_SA[i];
}

vi construct_SA(string& s)
{
    int n = s.size();
    int i, k, r;
    vi SA(n), RA(n);
    vi temp_SA(n, 0), temp_RA(n, 0);
    for (i = 0; i < n; ++i)
        RA[i] = s[i];
    for (i = 0; i < n; ++i)
        SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        counting_sort(s, SA, RA, temp_SA, temp_RA, k);
        counting_sort(s, SA, RA, temp_SA, temp_RA, 0);
        temp_RA[SA[0]] = r = 0;
        for (i = 1; i < n; ++i)
            temp_RA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; ++i)
            RA[i] = temp_RA[i];
        if (RA[SA[n - 1]] == n - 1)
            break;
    }
    return SA;
}

/**
 * Kasai's algorithm.
 */
vi compute_lcp(string& s, vi& sa)
{
    int i, L;
    int n = sa.size();
    vi plcp(n), phi(n), lcp(n);
    phi[sa[0]] = -1;
    for (int i = 1; i < n; ++i)
        phi[sa[i]] = sa[i - 1];
    for (i = L = 0; i < n; ++i) {
        // Special case.
        if (phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while (s[i + L] == s[phi[i] + L])
            L++;
        plcp[i] = L;
        L = max(L - 1, 0);
    }
    for (int i = 0; i < n; ++i)
        lcp[i] = plcp[sa[i]];
    return lcp;
}

class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int l1 = s.size(), l2 = t.size();
        int res = l2;
        int i = 0;
        for (int j = 0; j < l1; ++j) {
            char c = s[j];
            if (c == t[i]) {
                i++;
                res = min(res, l2 - i);
            }
        }

        return res;
    }
};