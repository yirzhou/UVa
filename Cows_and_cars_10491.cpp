#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

float solve(float NCOWS, float NCARS, float NSHOW)
{
    return NCOWS / (NCOWS + NCARS) * NCARS / (NCARS + NCOWS - NSHOW - 1) + NCARS / (NCARS + NCOWS) * (NCARS - 1) / (NCARS + NCOWS - NSHOW - 1);
}

int main()
{
    int NCOWS, NCARS, NSHOW;
    while (cin >> NCOWS >> NCARS >> NSHOW) {
        float res = solve(NCOWS, NCARS, NSHOW);
        printf("%.5f\n", res);
    }
}