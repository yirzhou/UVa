#include <algorithm>
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

class Solution {
public:
    vector<vi> jobs;
    vi memo;
    int search(int lo, int hi, int target)
    {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int val = jobs[mid][0];
            if (val == target)
                hi = mid;
            else if (val > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }

    int f(int i)
    {
        if (i == jobs.size())
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int profit = jobs[i][2];
        int nextidx = search(i + 1, jobs.size(), jobs[i][1]);
        int maxprofit = max(f(i + 1), profit + f(nextidx));
        return memo[i] = maxprofit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n = profit.size();
        jobs.clear();
        memo.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            jobs.pb({ startTime[i], endTime[i], profit[i] });
        }
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        return f(0);
    }
};
