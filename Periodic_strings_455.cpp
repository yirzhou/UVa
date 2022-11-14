#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define snl() scanf("\n")

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAX_N 100010

int b[MAX_N];
string t, p;

void preprocess()
{
    int m = p.size();
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && p[i] != p[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

bool kmp()
{
    int n = t.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && t[i] != p[j])
            j = b[j];
        i++;
        j++;
        if (j == m) {
            return true;
        }
    }
    return false;
}

int solve()
{
    int n = p.size();
    preprocess();
    for (int k = 1; k < n; ++k) {
        if (n % k == 0) {
            int rep = n / k;
            t.clear();
            while (rep--)
                t += p.substr(0, k);
            if (kmp())
                return k;
        }
    }
    return n;
}

int main()
{
    int N;
    si(N);
    while (N--) {
        getline(cin, p);
        while (p.size() == 0)
            getline(cin, p);
        memset(b, 0, sizeof(b));
        cout << solve() << endl;
        if (N)
            cout << endl;
    }
}