#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
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

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y)
        : x(_x)
        , y(_y) {};

    bool operator<(point_i other) const
    {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point_i other) const
    {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
};

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y)
        : x(_x)
        , y(_y) {};

    bool operator<(point other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point other) const
    {
        return (x == other.x && y == other.y);
    }
};

struct line {
    double a, b, c;
};

struct vec {
    double x, y;
    vec(double _x, double _y)
        : x(_x)
        , y(_y)
    {
    }
};

void points2line(const point& p1, const point& p2, line& l)
{
    if (fabs(p1.x - p2.x) < EPS)
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    fastio();
    int C, N, x, y;
    cin >> C;

    cout << fixed;
    cout.precision(2);

    while (C--) {
        cin >> N;
        vector<point> v;
        while (N--) {
            cin >> x >> y;
            point p(x, y);
            v.pb(p);
        }
        sort(ALL(v));

        point p = v.back();
        double res = 0.0;
        for (int i = v.size() - 2; i >= 0; --i) {
            if (v[i].y > p.y) {
                point a = v[i], b = v[i + 1], c;
                line l;
                points2line(a, b, l);
                c = point((-l.b / l.a) * p.y - (l.c / l.a), p.y);
                res += dist(a, c);
                p = a;
            }
        }

        cout << res << endl;
    }
}