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
typedef unsigned long long ull;
typedef vector<ll> vll;

ull memo[25][151];

ull gcd(ull a, ull b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ull lcm(ull a, ull b)
{
    return a * (b / gcd(a, b));
}

ull dp(int x, int k, int n, int score)
{
    if (memo[k][score] != -1)
        return memo[k][score];
    if (k == n)
        return memo[k][score] = (score >= x);
    ull ans = 0;
    for (int i = 1; i <= 6; ++i)
        ans += dp(x, k + 1, n, score + i);
    return memo[k][score] = ans;
}

int main()
{
    int n, x;
    while (cin >> n >> x && (n || x)) {
        for (int i = 0; i < 25; ++i)
            fill(memo[i], memo[i] + 151, -1);

        ull ans = dp(x, 0, n, 0);
        if (ans == 0) {
            cout << "0" << endl;
            continue;
        }

        ull total = pow(6, n);
        if (ans == total) {
            cout << "1" << endl;
            continue;
        }

        ull d = gcd(ans, total);
        cout << ans / d << "/" << total / d << endl;
    }
}