#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define gl(s) getline(cin, s)

typedef vector<int> vi;
typedef pair<int, int> ii;

int N, M, T;
string s;
vector<vi> A;

int main()
{
    gl(s);
    T = stoi(s);
    while (T--) {

        A = vector<vi>(8);
        for (int i = 0; i < 10; ++i) {
            gl(s);

            M = s.size() - 2;
            if (i > 0 && i < 9) {
                for (int j = 1; j < s.size() - 1; ++j) {
                    if (s[j] == '/')
                        A[i - 1].pb(0);
                    else
                        A[i - 1].pb(1);
                }
            }
        }

        for (int j = 1; j <= M; ++j) {
            int c = 0;

            for (int i = 0; i < 8; ++i) {
                c += (A[i][j - 1] == 1 ? (1 << i) : 0);
            }
            printf("%c", c);
        }
        printf("\n");
        if (T)
            gl(s);
    }
}