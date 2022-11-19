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

#define MAXN 1000007

int bs[MAXN];
ll _sieve_size;
vector<ll> primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    for (size_t i = 0; i < MAXN; ++i)
        bs[i] = 1;

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

int main()
{
    sieve(1000000);
    int L, U;
    while (cin >> L >> U) {
        int prev = -1;
        int mindiff = INT_MAX, maxdiff = INT_MIN;
        int a, b, c, d;
        for (int i = L; i <= U; ++i) {
            if (is_prime(i)) {
                if (prev != -1) {
                    int diff = i - prev;
                    if (diff < mindiff)
                        mindiff = diff, a = prev, b = i;
                    if (diff > maxdiff)
                        maxdiff = diff, c = prev, d = i;
                }
                prev = i;
            }
        }
        if (mindiff == INT_MAX || maxdiff == INT_MIN) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }

        cout << a << "," << b << " are closest, " << c << "," << d << " are most distant." << endl;
    }
}