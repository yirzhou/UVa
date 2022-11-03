#include <bits/stdc++.h>

using namespace std;

unordered_map<char, vector<char>> G;
unordered_map<char, int> K;
int V[26];
int T, N;

vector<char> path;
vector<string> ans;

string S;

void dfs(char node)
{
    int code = node - 'A';
    if (V[code])
        return;
    V[code] = 1;
    path.push_back(node);

    for (auto& neighbor : G[node]) {
        K[neighbor]--;
    }

    for (auto& [v, d] : K) {
        if (v != node && d == 0) {
            dfs(v);
        }
    }

    for (auto& neighbor : G[node])
        K[neighbor]++;

    if (path.size() == N) {
        string s;
        for (auto c : path) {
            s += c;
        }
        ans.push_back(s);
    }
    V[code] = 0;
    path.pop_back();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("\n");
        G.clear();
        K.clear();
        N = 0;
        memset(V, 0, sizeof(V));
        getline(cin, S);
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                K[S[i]] = 0;
                N++;
            }
        }

        getline(cin, S);
        for (int i = 0; i < S.size(); i += 4) {
            char a = S[i], b = S[i + 2];
            K[b]++;
            G[a].push_back(b);
        }

        path.clear();
        ans.clear();
        for (auto& [v, d] : K) {
            if (d == 0) {
                dfs(v);
            }
        }
        sort(ans.begin(), ans.end());
        if (!ans.size())
            printf("NO\n");
        for (auto& s : ans) {
            for (int i = 0; i < N; ++i) {
                printf(i == N - 1 ? "%c\n" : "%c ", s[i]);
            }
        }

        if (T)
            printf("\n");
    }
}
