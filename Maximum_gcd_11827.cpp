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

int main()
{
    int N;

    std::string str;
    getline(cin, str);
    N = stoi(str);

    while (N--) {
        vi A;
        int a;
        std::getline(cin, str);
        std::istringstream sstr(str);
        while (sstr >> a)
            A.pb(a);

        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                res = max(res, gcd(A[i], A[j]));
            }
        }

        cout << res << endl;
    }
}