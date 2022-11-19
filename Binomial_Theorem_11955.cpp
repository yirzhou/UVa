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

#define MAXN 105

vector<vector<ll>> C;
string s;

void pascal()
{
    C.pb({ 1 });
    for (int i = 1; i < MAXN; ++i) {

        vector<ll> elems;
        for (int j = 0; j < i + 1; ++j) {
            ll s = j == 0 ? C[i - 1][j] : (j >= C[i - 1].size() ? C[i - 1][j - 1] : C[i - 1][j - 1] + C[i - 1][j]);
            elems.pb(s);
        }
        C.pb(elems);
    }
}

int main()
{
    int N, k;
    si(N);
    scanf("\n");
    pascal();
    for (int n = 1; n <= N; ++n) {
        getline(cin, s);
        int plus = s.find('+'), lb = 1, rb = s.find(')');
        string a = s.substr(1, plus - lb), b = s.substr(plus + 1, rb - plus - 1);
        k = stoi(s.substr(rb + 2, s.size() - rb - 1));

        printf("Case %d: ", n);

        for (int i = 0; i < C[k].size(); ++i) {

            if (i)
                printf("+");
            if (C[k][i] > 1)
                printf("%lld*", C[k][i]);

            if (C[k].size() - i - 1) {
                cout << a;
                if (C[k].size() - i - 1 > 1)
                    printf("^%d", (int)C[k].size() - i - 1);
            }

            if (i > 0 && i < C[k].size() - 1)
                cout << "*";
            if (i) {
                cout << b;
                if (i > 1)
                    printf("^%d", i);
            }
        }
        printf("\n");
    }
}