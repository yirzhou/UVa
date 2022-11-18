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

ii GC(int n)
{
    int i = 1;
    int j = 1;
    int k = 1;

    while (k < n) {
        j++, k++;

        if (k == n)
            break;

        while (j > 1 && k < n) {
            i++, j--, k++;
        }

        if (k == n)
            break;

        i++, k++;

        if (k == n)
            break;

        while (i > 1 && k < n) {
            i--, j++, k++;
        }
    }
    return { i, j };
}

int main()
{
    int n;
    while (si(n) != EOF) {
        ii res = GC(n);
        printf("TERM %d IS %d/%d\n", n, res.first, res.second);
    }
}