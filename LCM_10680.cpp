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

#define MAXN 1000007

bitset<MAXN> bs;
ll _sieve_size;
vi primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.pb((int)i);
        }
    }
}

bool is_prime(ll n)
{
    if (n <= _sieve_size)
        return bs[n];
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] * primes[i] > n)
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

template <typename T>
T modpow(T base, T exp, T M)
{
    base %= M;
    T result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return result;
}

int maxpow(int base, int x)
{
    int cnt = 0;
    while (x / base > 0) {
        cnt++;
        x /= base;
    }
    return cnt;
}

void solve(int N)
{
    vector<ii> factors;
    for (int i = 0; i < primes.size() && primes[i] <= N; ++i) {
        int z = maxpow(primes[i], N);
        factors.pb({ primes[i], z });
    }

    // Handle 2 * 5 = 10
    if (factors.size() >= 3) {
        factors[0].second -= factors[2].second;
        factors[2].second = 0;
    }

    int ans = 1;
    for (auto& [factor, exp] : factors) {
        ans = ans * pow(factor, exp);
        ans %= 10;
    }

    cout << ans << endl;
}

int main()
{
    sieve(MAXN);
    int N;
    while (cin >> N && N) {
        if (N == 1)
            cout << N << endl;
        else {
            solve(N);
        }
    }
}