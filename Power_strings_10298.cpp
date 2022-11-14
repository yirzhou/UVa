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

vi b;
string t, p;

void preprocess()
{
    int m = p.size();
    b.assign(m, 0);
    b[0] = -1;
    int i = 0, j = -1;
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

int main()
{
    while (cin >> p && p != ".") {
        int length = p.size();
        preprocess();
        printf("%d\n", length / (length - b[length - 1]));
    }
}