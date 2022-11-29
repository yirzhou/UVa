#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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

#define MAXN 100000

typedef bitset<MAXN> bs;

unordered_set<size_t> S1, S2;
hash<bs> hash_fn;

vector<size_t> P;

int ptr = 0;
const size_t M = 1e9 + 7;

int parse(string& s)
{
    int num = 0;
    while (ptr < s.size() && s[ptr] >= '0' && s[ptr] <= '9') {
        num *= 10;
        num += s[ptr++] - '0';
    }
    return num;
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

size_t f(string& s, unordered_set<size_t>& S)
{
    size_t hashval = 0;
    if (ptr >= s.size()) {
        return hashval;
    }

    if (s[ptr] == ')') {
        ptr++;
        return hashval;
    }

    if (s[ptr] == ',')
        ptr++;

    // Parse left tree
    if (s[ptr] == '(') {
        ptr++, hashval = (hashval + f(s, S) % M) % M;
    } else if (is_digit(s[ptr])) {
        int num = parse(s);
        // Set bit
        hashval = (hashval + (num)*P[num - 1] % M) % M;
        S.emplace(hashval);
    }

    if (ptr < s.size())
        hashval = (hashval + f(s, S) % M) % M;

    S.emplace(hashval);
    // Compute hash
    return hashval;
}

void prepare(int N)
{
    P.assign(N, 0);
    P[0] = 1;
    for (int i = 1; i < N; ++i) {
        P[i] = (P[i - 1] * MAXN) % M;
    }
}

int main()
{
    fastio;
    int N;
    string s1, s2;
    getline(cin, s1);
    N = stoi(s1);
    prepare(N);
    getline(cin, s1);
    getline(cin, s2);
    ptr = 0, f(s1, S1);
    ptr = 0, f(s2, S2);

    int res = 0;
    for (auto& hashval : S1) {
        if (S2.count(hashval))
            res++;
    }

    cout << res << endl;
}