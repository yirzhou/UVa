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

string s;

int main()
{
    int N;
    string pass;
    while (cin >> N >> s) {
        unordered_map<string, ll> cnt;
        ll size = s.size();
        for (ll i = 0; i + N <= size; ++i) {
            cnt[s.substr(i, N)]++;
        }

        ll maxf = 0;
        string ans = "";

        for (auto i : cnt) {
            if (i.second > maxf) {
                maxf = i.second;
                ans = i.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}