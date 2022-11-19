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

ll cal_n(int n)
{
    ll temp = 1;
    for (int i = 2; i <= n; i++)
        temp = temp * i;
    return temp;
}

ll nCr(int n, int r)
{
    return cal_n(n) / (cal_n(r) * cal_n(n - r));
}

int main()
{

    int n;
    int caseno = 0;
    while (cin >> n) {
        if (caseno++)
            cout << endl;
        if (n == 1)
            cout << n << endl;
        else
            printf("%lld\n", nCr(2 * n, n) / (n + 1));
    }
}