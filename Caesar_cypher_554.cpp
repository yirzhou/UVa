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

#define MOD 27

unordered_set<string> dict;
string s, cypher;

unordered_map<int, int> C, RC;

void shift(string& sc, int i)
{
    for (auto& c : sc) {
        c = RC[(C[c] + i) % MOD];
    }
}

int main()
{
    int hash = 0;
    C[' '] = 0;
    RC[0] = ' ';
    for (int i = 0; i < 26; ++i) {
        C['A' + i] = i + 1;
        RC[i + 1] = 'A' + i;
    }

    while (getline(cin, s) && s.size()) {
        if (s[0] == '#') {
            hash = 1;
            continue;
        }
        if (hash) {
            cypher = string(s);
        } else
            dict.insert(s);
    }

    int mm = 0, shifts = 0;
    for (int i = 1; i < 27; ++i) {
        int matches = 0;
        string sc = string(cypher);
        shift(sc, i);
        int start = -1;
        for (int j = 0; j < sc.size(); ++j) {
            if (sc[j] == ' ' || j == sc.size() - 1) {
                string word = sc.substr(start + 1, j - start - 1);
                if (dict.count(word))
                    matches++;
                start = j;
            }
        }

        if (matches > mm) {
            mm = matches, shifts = i;
        }
    }

    shift(cypher, shifts);

    vector<string> words;
    int start = -1;
    for (int j = 0; j < cypher.size(); ++j) {
        if (cypher[j] == ' ' || j == cypher.size() - 1) {
            words.pb(cypher.substr(start + 1, j - start - 1));
            start = j;
        }
    }
    int cnt = 0, lo = 0;
    for (int hi = 0; hi < words.size(); ++hi) {
        cnt += words[hi].size();
        if (cnt + hi - lo > 60) {
            for (int i = lo; i < hi; ++i) {
                cout << words[i];
                if (i < hi - 1)
                    cout << " ";
            }
            cout << endl;
            lo = hi;
            cnt = words[lo].size();
        }
    }
    while (lo < words.size()) {
        cout << words[lo];
        if (lo < words.size() - 1)
            cout << " ";
        lo++;
    }
    cout << endl;
}