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

        int len = 1;
        seq[1] = s3[1];
        for (int i = 2; i <= p; ++i) {
            if (s3[i] > seq[len])
                seq[++len] = s3[i];
            else {
                int pos = lower_bound(seq.begin(), seq.begin() + len, s3[i]) - seq.begin();
                seq[pos] = s3[i];
            }
        }

        printf("Case %d: %d\n", caseno, len);
    }
}