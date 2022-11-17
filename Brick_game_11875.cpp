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

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, val, res;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> val;
            if (i == N / 2)
                res = val;
        }

        printf("Case %d: %d\n", t, res);
    }
}