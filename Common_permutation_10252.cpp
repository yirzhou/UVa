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

int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        unordered_map<int, int> cnt1, cnt2;
        for (auto& c : a)
            cnt1[c]++;
        for (auto& c : b)
            cnt2[c]++;
        vector<ii> res;
        for (auto p : cnt1) {
            if (cnt2.count(p.first))
                res.pb({ p.first, min(p.second, cnt2[p.first]) });
        }

        sort(res.begin(), res.end());
        for (auto& [c, f] : res) {
            for (int i = 0; i < f; ++i)
                printf("%c", c);
        }
        cout << endl;
    }
}