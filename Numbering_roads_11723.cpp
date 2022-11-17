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
    int R, N, caseno = 1;
    while (cin >> R >> N && (R && N)) {
        int res = ceil((double)max(R - N, 0) / N);
        printf("Case %d: ", caseno++);
        if (res > 26)
            printf("impossible\n");
        else
            printf("%d\n", res);
    }
}