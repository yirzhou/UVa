#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

int freq[10] = { 0 }, sum;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool solve()
{
    return (freq[0] + freq[3] + freq[6] + freq[9]) % 2;
}

void init(string& s)
{
    fill(freq, freq + 10, 0);
    sum = 0;
    for (auto& c : s) {
        sum += (c - '0');
        freq[c - '0']++;
    }
}

int main()
{
    fastio();
    int T;
    string s;
    getline(cin, s);
    T = stoi(s);

    for (int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": ";
        getline(cin, s);
        init(s);
        if (sum % 3 == 0) {
            if (solve())
                cout << "S";
            else
                cout << "T";
        } else {
            int i;
            for (i = 1; i < 10; ++i) {
                if (freq[i] > 0 && (sum - i) % 3 == 0) {
                    freq[i]--;
                    break;
                }
            }

            if (i < 10 && !solve())
                cout << "S";
            else
                cout << "T";
        }

        cout << endl;
    }
}