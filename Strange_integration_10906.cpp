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

struct node {
    char op;
    string s;
};

unordered_map<string, node> mm;

node get(string& a)
{
    if (mm.count(a))
        return mm[a];
    return { '!', a };
}

void f(string& a, string& b, char op, string& c)
{

    node na = get(a), nb = get(b), nc;
    nc.op = op;
    if (na.op == '+' && op == '*')
        nc.s = "(" + na.s + ")";
    else
        nc.s = na.s;
    nc.s += op;
    if (nb.op == '+' || (op == '*' && nb.op == '*'))
        nc.s += "(" + nb.s + ")";
    else
        nc.s += nb.s;
    mm[c] = nc;
}

int main()
{
    int t, n;
    string a, b, c, es;
    char op;
    si(t);
    for (int i = 1; i <= t; ++i) {
        mm.clear();
        si(n);
        for (int j = 0; j < n; ++j) {
            cin >> c >> es >> a >> op >> b;
            f(a, b, op, c);
        }

        printf("Expression #%d: %s\n", i, mm[c].s.c_str());
    }
}