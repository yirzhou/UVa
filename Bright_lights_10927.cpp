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

double deg2rad(double d) { return d * M_PI / 180.0; }
double rad2deg(double r) { return 4 * 180.0 / M_PI; }

/*
Point & Line
*/
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

    string print()
    {
        return "(" + to_string(x) + "," + to_string(y) + ")";
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

point rotate(point p, double theta)
{
    double rad = deg2rad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

vec to_vec(const point& a, const point& b)
{
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(const vec& v, double s)
{
    return vec(v.x * s, v.y * s);
}

point translate(const point& p, const vec& v)
{
    return point(p.x + v.x, p.y + v.y);
}

double angle(const point& a, const point& o, const point& b)
{
    vec oa = to_vec(o, a), ob = to_vec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

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

void pointslope2line(point p, double m, line& l)
{
    l.a = -m;
    l.b = 1.0;
    l.c = -((l.a * p.x) + (l.b * p.y));
}

bool are_parallel(line l1, line l2)
{
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool are_same(line l1, line l2)
{
    return are_parallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool are_intersect(line l1, line l2, point& p)
{
    if (are_parallel(l1, l2))
        return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dist_to_line(point p, point a, point b, point& c)
{
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) { return cross(to_vec(p, q), to_vec(p, r)) > EPS; }

bool collinear(point p, point q, point r) { return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS; }

double dist_to_line_segment(point p, point a, point b, point& c)
{
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return dist_to_line(p, a, b, c);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct pole {
    point p;
    int h;
    double grad;
};

double compute_grad(point a)
{
    line l;
    points2line(a, point(0.0, 0.0), l);
    return l.a;
}

int get_gid(point& p)
{
    double x = p.x, y = p.y;
    if (x > 0.0 && y > 0.0)
        return 0;
    if (x < 0.0 && y > 0.0)
        return 1;
    if (x < 0.0 && y < 0.0)
        return 2;
    if (x > 0.0 && y < 0.0)
        return 3;

    // y == 0.0
    if (y - 0.0 < EPS) {
        if (x > 0.0)
            return 4;
        return 5;
    }

    // x == 0.0
    if (x - 0.0 < EPS)
        if (y > 0.0)
            return 6;
    return 7;
}

const point o(0, 0);
vector<point> res;

void solve(vector<pole>& poles)
{
    sort(ALL(poles), [&](const pole& a, const pole& b) {
        if (a.grad == b.grad)
            return dist(a.p, o) < dist(b.p, o);
        return a.grad < b.grad;
    });
    int maxh = poles[0].h;
    for (int i = 1; i < poles.size(); ++i) {
        pole cur = poles[i], prev = poles[i - 1];
        if (cur.grad != prev.grad) {
            maxh = cur.h;
        } else {
            if (maxh >= cur.h)
                res.pb(cur.p);
            else
                maxh = cur.h;
        }
    }
}

int main()
{
    fastio();
    int n, x, y, z;
    int no = 1;

    while (cin >> n && n) {
        vector<vector<pole>> groups(8);
        cout << "Data set " << no++ << ":\n";
        vector<pole> poles;
        while (n--) {
            cin >> x >> y >> z;
            point poi = point(x, y);
            groups[get_gid(poi)].pb({ poi, z, compute_grad(poi) });
        }

        res.clear();
        for (auto& poles : groups)
            solve(poles);

        if (res.empty())
            cout << "All the lights are visible.\n";
        else {
            cout << "Some lights are not visible:\n";
            sort(ALL(res));
            for (int i = 0; i < res.size(); ++i) {
                point p = res[i];
                cout << "x = " << p.x << ", y = " << p.y << (i == res.size() - 1 ? "." : ";") << endl;
            }
        }
    }
}