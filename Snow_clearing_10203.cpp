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

int T, x, y;
double dist;

string s;

int main()
{
    si(T);
    scanf("\n");

    while (T--) {
        dist = 0.0;
        double x1, y1, x2, y2;
        int i = 0;
        while (getline(cin, s) && s[0] != '\0') {
            if (i++ == 0)
                continue;
            sscanf(s.c_str(), "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            dist += hypot(x1 - x2, y1 - y2);
        }

        dist = dist / 1000;
        double hh = dist * 2 / 20;
        int mm = (int)round(hh * 60);
        printf("%d:%02d\n", mm / 60, mm % 60);
        if (T)
            printf("\n");
    }
}