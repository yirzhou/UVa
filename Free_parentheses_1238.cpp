#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

vi nums, sigs;

bool used[6005];
vector<vector<vi>> V;

string s;
int N;

void pre()
{
    int i = 0;
    nums.clear(), sigs.clear();
    memset(used, 0, sizeof used);
    while (i < s.size()) {
        if (s[i] == '+' || s[i] == '-') {
            sigs.pb(s[i] == '+' ? 1 : -1);
        } else if (s[i] != ' ') {
            int num = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0'), i++;
            nums.pb(num);
        }
        i++;
    }
    N = nums.size();
    V = vector<vector<vi>>(N + 1, vector<vi>(N + 1, vi(6005, 0)));
}

void f(int i, int open, int val)
{
    if (V[i][open][val + 3000])
        return;
    V[i][open][val + 3000] = 1;
    if (i == N) {
        used[val + 3000] = true;
        return;
    }

    int nval = val + nums[i] * sigs[i] * ((open % 2 == 0) ? 1 : -1);
    if (sigs[i] == -1)
        f(i + 1, open + 1, nval);
    if (open > 0)
        f(i + 1, open - 1, nval);
    f(i + 1, open, nval);
}

int main()
{
    fastio;

    while (getline(cin, s) && s.size()) {
        s = "+ " + s;
        pre();

        f(0, 0, 0);
        int res = 0;
        for (int i = 0; i < 6005; ++i)
            if (used[i] == 1)
                res++;
        cout << res << endl;
    }
    return 0;
}