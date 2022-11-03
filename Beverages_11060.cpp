#include <bits/stdc++.h>
#include <queue>

using namespace std;

unordered_map<string, vector<string>> G;
unordered_map<int, int> K;

int n, m, t = 1;
string line;
unordered_map<string, int> M;
unordered_map<int, string> INV_M;
vector<string> order;

int main()
{
    while (scanf("%d\n", &n) != EOF) {
        M.clear();
        K.clear();
        INV_M.clear();
        order.clear();
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            M[line] = i;
            INV_M[i] = line;
            K[i] = 0;
        }
        scanf("%d\n", &m);
        while (m--) {
            getline(cin, line);
            int si = line.find(' ');
            string a = line.substr(0, si), b = line.substr(si + 1, line.size() - si - 1);
            G[a].push_back(b);
            K[M[b]]++;
        }
        // kahn's algorithm.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (K[j] == 0) {
                    K[j] = -1;
                    order.push_back(INV_M[j]);
                    for (auto& nei : G[INV_M[j]]) {
                        K[M[nei]]--;
                    }
                    G[INV_M[j]].clear();
                    break;
                }
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", t++);

        for (int i = 0; i < order.size(); ++i) {
            cout << " " << order[i];
        }
        printf(".\n\n");
    }
}
