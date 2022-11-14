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

vector<string> strs;
string s;

bool solve()
{
    int n = strs.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && strs[i].size() <= strs[j].size()) {
                if (strs[j].substr(0, strs[i].size()) == strs[i])
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    int setno = 1;
    while (getline(cin, s) && s.size()) {
        if (s[0] == '9') {
            if (solve())
                printf("Set %d is immediately decodable\n", setno++);
            else
                printf("Set %d is not immediately decodable\n", setno++);
            strs.clear();
        }
        strs.pb(s);
    }
}