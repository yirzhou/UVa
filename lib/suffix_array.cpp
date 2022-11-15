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

vi sort_cyclic_shifts(const string& s)
{
    int n = s.size();
    const int alphabet = 256;
    vi p(n), c(n), cnt(max(n, alphabet), 0);
    for (int i = 0; i < n; ++i)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; ++i)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            ii cur = { c[p[i]], c[(p[i] + (1 << h)) % n] };
            ii prev = { c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n] };
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vi suffix_array_construction(string s)
{
    s += "$";
    vi sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}