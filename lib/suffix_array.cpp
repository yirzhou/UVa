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

// vi sort_cyclic_shifts(const string& s)
// {
//     int n = s.size();
//     const int alphabet = 256;
//     vi p(n), c(n), cnt(max(n, alphabet), 0);
//     for (int i = 0; i < n; ++i)
//         cnt[s[i]]++;
//     for (int i = 1; i < alphabet; ++i)
//         cnt[i] += cnt[i - 1];
//     for (int i = 0; i < n; ++i)
//         p[--cnt[s[i]]] = i;
//     c[p[0]] = 0;
//     int classes = 1;
//     for (int i = 1; i < n; ++i) {
//         if (s[p[i]] != s[p[i - 1]])
//             classes++;
//         c[p[i]] = classes - 1;
//     }

//     vi pn(n), cn(n);
//     for (int h = 0; (1 << h) < n; ++h) {
//         for (int i = 0; i < n; ++i) {
//             pn[i] = p[i] - (1 << h);
//             if (pn[i] < 0)
//                 pn[i] += n;
//         }
//         fill(cnt.begin(), cnt.begin() + classes, 0);
//         for (int i = 0; i < n; ++i)
//             cnt[c[pn[i]]]++;
//         for (int i = 1; i < classes; ++i)
//             cnt[i] += cnt[i - 1];
//         for (int i = n - 1; i >= 0; --i)
//             p[--cnt[c[pn[i]]]] = pn[i];
//         cn[p[0]] = 0;
//         classes = 1;
//         for (int i = 1; i < n; ++i) {
//             ii cur = { c[p[i]], c[(p[i] + (1 << h)) % n] };
//             ii prev = { c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n] };
//             if (cur != prev)
//                 ++classes;
//             cn[p[i]] = classes - 1;
//         }
//         c.swap(cn);
//     }
//     return p;
// }

// vi suffix_array_construction(string s)
// {
//     s += "$";
//     vi sorted_shifts = sort_cyclic_shifts(s);
//     sorted_shifts.erase(sorted_shifts.begin());
//     return sorted_shifts;
}
