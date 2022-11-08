#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define N 26
#define INF 1000000000

unordered_map<int, vi> G;
int t[N];

int memo[N];
unordered_set<int> nodes;

string s;

int f(int u)
{
    if (memo[u] != -1)
        return memo[u];
    int ans = t[u];

    for (auto& v : G[u]) {
        ans = min(ans, t[u] + f(v));
    }

    return memo[u] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("\n");
    for (int i = 0; i < n; ++i) {
        if (i)
            printf("\n");
        fill(t, t + N, 0);
        fill(memo, memo + N, -1);
        G.clear();
        nodes.clear();
        while (getline(cin, s) && s.size()) {
            int u = s[0] - 'A';
            nodes.emplace(u);
            int j = 2;
            for (; j < s.size() && '0' <= s[j] && s[j] <= '9'; ++j)
                ;

            int cost = stoi(s.substr(2, j++ - 2));
            t[u] = -cost;
            while (j < s.size()) {
                int parent = s[j++] - 'A';
                G[parent].push_back(u);
            }
        }

        int res = 0;
        for (auto& u : nodes) {
            res = min(res, f(u));
        }
        printf("%d\n", -res);
    }
}