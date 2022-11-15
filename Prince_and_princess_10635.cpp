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

#define MAXN 62505

vi s1, s2, s3, seq;
int t, n, p, q;

int lis(vi& nums, int lo, int hi)
{

    vi seq;
    for (int i = lo; i <= hi; ++i) {
        int num = nums[i];
        int idx = lower_bound(seq.begin(), seq.end(), num) - seq.begin();
        if (idx == seq.size())
            seq.pb(num);
        else
            seq[idx] = num;
    }
    return seq.size();
}

int main()
{
    si(t);
    s1.assign(MAXN, 0);
    s2.assign(MAXN, 0);
    seq.assign(MAXN, 0);
    for (int caseno = 1; caseno <= t; ++caseno) {
        siii(n, p, q);
        p++;
        q++;
        for (int i = 1; i <= p; ++i)
            si(s1[i]);
        for (int i = 1; i <= q; ++i)
            si(s2[i]);

        s3.assign(MAXN, INT_MAX);
        for (int i = 1; i <= p; ++i) {
            for (int j = 1; j <= q; ++j) {
                if (s1[i] == s2[j])
                    s3[i] = j;
            }
        }

        int len = lis(s3, 1, p);

        printf("Case %d: %d\n", caseno, len);
    }
}