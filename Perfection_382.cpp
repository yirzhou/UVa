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

void solve(int n)
{
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    int digits = (int)log10(n) + 1;
    for (int i = 0; i < 5 - digits; ++i)
        cout << " ";
    printf(sum == n ? "%d  PERFECT\n" : (sum < n ? "%d  DEFICIENT\n" : "%d  ABUNDANT\n"), n);
}

int main()
{
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> n && n != 0) {
        solve(n);
    }
    cout << "END OF OUTPUT" << endl;
}