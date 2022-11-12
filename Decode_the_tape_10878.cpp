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

#define N 11

string s;

int main()
{
    getline(cin, s);

    vector<int> A;
    bool started = false;
    while (getline(cin, s) && s[0] != '_') {

        A.clear();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '|' && s[i] != '.') {
                int c = s[i] == ' ' ? 0 : 1;
                A.pb(c);
            }
        }

        int c = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            c += (A[i] ? 1 << (A.size() - i - 1) : 0);
        }
        printf("%c", c);
    }
}