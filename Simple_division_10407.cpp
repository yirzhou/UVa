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
typedef vector<ll> vll;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

int solve(vi& arr)
{
    sort(arr.begin(), arr.end());
    int sub = arr[0];
    for (auto& num : arr) {
        num -= sub;
        num = abs(num);
    }
    int i = 0;
    for (; i < arr.size() && arr[i] == 0; ++i)
        ;
    int d = arr[i++];
    for (; i < arr.size(); ++i) {
        d = min(d, gcd(d, arr[i]));
    }
    return d;
}

int main()
{
    vi seq;
    int n;
    while (cin >> n && n != 0) {
        seq.pb(n);
        while (cin >> n && n != 0)
            seq.pb(n);
        cout << solve(seq) << endl;
        seq.clear();
    }
}