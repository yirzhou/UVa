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

ll factorials[21];

void init()
{
    factorials[0] = 1;
    factorials[1] = 1;
    for (int i = 2; i <= 20; ++i)
        factorials[i] = i * factorials[i - 1];
}

ll solve(string& s)
{
    unordered_map<char, int> freqs;
    for (auto& c : s)
        freqs[c]++;

    int n = s.size();
    ll res = factorials[n];
    for (auto& [k, v] : freqs)
        res /= factorials[v];
    return res;
}

int main()
{
    int N;
    string s;
    getline(cin, s);
    N = stoi(s);
    init();
    for (int n = 1; n <= N; ++n) {
        getline(cin, s);
        printf("Data set %d: %lld\n", n, solve(s));
    }
}