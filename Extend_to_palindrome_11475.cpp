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

int solve(string& t)
{
    int n = t.size();
    vi b(n, 0);
    b[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = b[i - 1];
        while (j > 0 && t[i] != t[j])
            j = b[j - 1];
        if (t[i] == t[j])
            j++;
        b[i] = j;
    }
    return b[n - 1];
}

int main()
{
    string s;
    while (cin >> s) {
        string p(s);
        reverse(s.begin(), s.end());
        string t = s + "#" + p;
        int len = solve(t);
        if (p.size() - len) {
            for (int i = p.size() - len - 1; i >= 0; --i) {
                p += p[i];
            }
        }
        cout << p << endl;
    }
}