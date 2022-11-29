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
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

double deg2rad(double d) { return d * M_PI / 180.0; }
double rad2deg(double r) { return r * 180.0 / M_PI; }

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
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point_i other) const
    {
        return (x == other.x && y == other.y);
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
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point other) const
    {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
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

point get_midpoint(point& a, point& b)
{
    return point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
}

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

/*
Circle
*/

int inside_circle(const point& p, const point& c, double r)
{
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = pow(dx, 2.0) + pow(dy, 2.0), rSq = pow(r, 2.0);
    return rSq - Euc > EPS ? 1 : (fabs(Euc - rSq) < EPS ? 0 : -1); // in/border/out
}

bool circle2PtsRad(point p1, point p2, double r, point& c)
{
    double d2 = pow((p1.x - p2.x), 2.0) + pow((p1.y - p2.y), 2.0);
    double det = r * r / d2 - 0.25;
    if (det < EPS)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

/*
Triangle
*/

double perimeter(double ab, double bc, double ca)
{
    return (ab + bc + ca);
}

double area(double ab, double bc, double ca)
{
    double s = perimeter(ab, bc, ca) / 2.0;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

double r_in_circle(double ab, double bc, double ca)
{
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double r_in_circle(point a, point b, point c)
{
    return r_in_circle(dist(a, b), dist(b, c), dist(a, c));
}

int in_circle(point p1, point p2, point p3, point& ctr, double& r)
{
    r = r_in_circle(p1, p2, p3);
    if (fabs(r) < EPS)
        return 0;
    line l1, l2;
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(to_vec(p2, p3), ratio / (1 + ratio)));
    points2line(p1, p, l1);

    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(to_vec(p1, p3), ratio / (1 + ratio)));
    points2line(p2, p, l2);

    are_intersect(l1, l2, ctr);
    return 1;
}

double r_circum_circle(double ab, double bc, double ca)
{
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double r_circum_circle(point a, point b, point c)
{
    return r_circum_circle(dist(a, b), dist(b, c), dist(c, a));
}
double perp_slope(double slope)
{
    return pow((slope * -1.0), -1.0);
}

point get_circumcenter(point& a, point& b, point& c)
{
    point m1 = get_midpoint(a, b), m2 = get_midpoint(b, c);
    line l1, l2;
    points2line(a, b, l1), points2line(b, c, l2);
    double perp1 = perp_slope(-l1.a / l1.b), perp2 = perp_slope(-l2.a / l2.b);
    line perpbi1, perpbi2;
    pointslope2line(m1, perp1, perpbi1), pointslope2line(m2, perp2, perpbi2);
    point circum;
    are_intersect(perpbi1, perpbi2, circum);
    if (fabs(circum.x - 0.0) < EPS)
        circum.x = 0.0;
    if (fabs(circum.y - 0.0) < EPS)
        circum.y = 0.0;
    return circum;
}

int insideRectangle(double x, double y, double w, double h, double a, double b)
{
    if ((x < a) && (a < x + w) && (y < b) && (b < y + h))
        return 1; // strictly inside
    else if ((x <= a) && (a <= x + w) && (y <= b) && (b <= y + h))
        return 0; // at border
    else
        return -1; // outside
}

/*
Polygon - represented as vector<point>
*/

double perimeter(const vector<point>& P)
{
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i)
        ans += dist(P[i], P[i + 1]);
    return ans;
}

double area(const vector<point>& P)
{
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i)
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0;
}

// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double area_alternative(const vector<point>& P)
{
    double ans = 0.0;
    point O(0.0, 0.0); // O = the Origin
    for (int i = 0; i < (int)P.size() - 1; ++i) // sum of signed areas
        ans += cross(to_vec(O, P[i]), to_vec(O, P[i + 1]));
    return fabs(ans) / 2.0;
}

// returns true if we always make the same turn
// while examining all the edges of the polygon one by one
bool isConvex(const vector<point>& P)
{
    int n = (int)P.size();
    // a point/sz=2 or a line/sz=3 is not convex
    if (n <= 3)
        return false;
    bool firstTurn = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < n - 1; ++i)
        // remember one result,
        // compare with the others
        if (ccw(P[i], P[i + 1], P[(i + 2) == n ? 1 : i + 2]) != firstTurn)
            return false; // different -> concave
    return true; // otherwise -> convex
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(point pt, const vector<point>& P)
{
    int n = (int)P.size();
    if (n <= 3)
        return -1; // avoid point or line
    bool on_polygon = false;
    for (int i = 0; i < n - 1; ++i) // on vertex/edge?
        if (fabs(dist(P[i], pt) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < EPS)
            on_polygon = true;
    if (on_polygon)
        return 0;
    double sum = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]);
        else
            sum -= angle(P[i], pt, P[i + 1]);
    }
    return fabs(sum) > M_PI ? 1 : -1;
}

// compute the intersection point between line segment p-q and line A-B
point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

// cuts polygon Q along the line formed by point A->point B (order matters)
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point A, point B, const vector<point>& Q)
{
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); ++i) {
        double left1 = cross(to_vec(A, B), to_vec(A, Q[i])), left2 = 0;
        if (i != (int)Q.size() - 1)
            left2 = cross(to_vec(A, B), to_vec(A, Q[i + 1]));
        if (left1 > -EPS)
            P.push_back(Q[i]); // Q[i] is on the left
        if (left1 * left2 < -EPS) // crosses line AB
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], A, B));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    return P;
}

vector<point> CH_Graham(vector<point>& Pts)
{
    vector<point> P(Pts);
    int n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n - 1]))
            P.push_back(P[0]);
        return P;
    }
    int P0 = min_element(P.begin(), P.end()) - P.begin();
    swap(P[0], P[P0]);
    sort(++P.begin(), P.end(), [&](point a, point b) {
        return ccw(P[0], a, b);
    });

    vector<point> S({ P[n - 1], P[0], P[1] });
    int i = 2;
    while (i < n) {
        int j = (int)S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i]))
            S.push_back(P[i++]);
        else
            S.pop_back();
    }
    return S;
}

vector<point> CH_Andrew(vector<point>& Pts)
{
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n);
    sort(Pts.begin(), Pts.end());
    for (int i = 0; i < n; ++i) {
        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

int main()
{
    // TODO: unfinished
    fastio;
    precision(2);
    int cnt = 1, N;
    point c;
    vector<point> pts, ch;

    while (cin >> N && N) {
        pts.clear(), ch.clear();
        double x, y;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            pts.pb(point(x, y));
        }
        double MIN = 1e12;
        ch = CH_Graham(pts);
        int k = ch.size();
        for (int i = 0; i < k; ++i) {
            double mx = 0.0;
            for (int j = 0; j < k; ++j) {
                mx = max(mx, dist_to_line(ch[j], ch[i], ch[(i + 1) % (k - 1)], c));
            }
            MIN = min(MIN, mx);
        }

        cout << "Case " << cnt++ << ": " << MIN << endl;
    }
}