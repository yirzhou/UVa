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

#define MAX_BOLTS 500
#define MAX_NUTS 500
/*~global~copy~of~the~input~data~*/

int nuts, bolts;
int fits[MAX_BOLTS][MAX_NUTS];
vector<vi> G;
void read_input_data(void)
{
    int n, b;
    scanf("%d%d", &bolts, &nuts);
    G = vector<vi>(bolts);
    int fit = 0;
    for (b = 0; b < bolts; b++) {
        for (n = 0; n < nuts; n++) {
            scanf("%d", &fit);
            if (fit)
                G[b].pb(n + bolts);
        }
    }
}

vi vis, match;

int Aug(int l)
{
    if (vis[l])
        return 0;
    vis[l] = 1;

    for (auto& r : G[l]) {
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int cases, caseno;
    scanf("%d", &cases);
    for (caseno = 1; caseno <= cases; caseno++) {
        read_input_data();

        int MCBM = 0;
        match.assign(bolts + nuts, -1);
        for (int l = 0; l < bolts; ++l) {
            vis.assign(bolts, 0);
            MCBM += Aug(l);
        }

        printf("Case %d: ", caseno);
        printf("a maximum of %d nuts and bolts ", MCBM);
        printf("can be fitted together\n");
    }
    return 0;
}