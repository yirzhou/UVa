#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
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
typedef vector<vi> vii;

class Solution {
public:
    struct cmp1 {
        bool operator()(const pair<int, ll>& a, const pair<int, ll>& b)
        {
            if (a.se == b.se)
                return a.fi > b.fi;
            return a.se > b.se;
        }
    };

    struct cmp2 {
        bool operator()(const int& a, const int& b) { return a > b; }
    };
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(ALL(meetings), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        // {id, endtime};
        priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp1> busy;
        priority_queue<int, vector<int>, cmp2> free;
        int m = meetings.size();
        int cnt[100] = { 0 };
        for (int r = 0; r < n; ++r)
            busy.push({ r, 0 });

        for (int i = 0; i < m; ++i) {
            ll start = meetings[i][0], interval = meetings[i][1] - meetings[i][0], end = start + interval;

            while (busy.size() && busy.top().se <= start) {
                int r = busy.top().fi;
                busy.pop();
                free.push(r);
            }

            if (free.size()) {
                int r = free.top();
                free.pop();
                cnt[r]++;
                busy.push({ r, end });
            } else {
                auto p = busy.top();
                busy.pop();
                p.se += interval;
                cnt[p.fi]++;
                busy.push(p);
            }
        }

        int maxcnt = 0, res = 0;
        for (int r = 0; r < n; ++r) {
            if (cnt[r] > maxcnt)
                maxcnt = cnt[r], res = r;
        }

        return res;
    }
};

// int main()
// {

//     Solution s;
//     int n = 4;
//     vii meetings = { { 18, 19 }, { 3, 12 }, { 17, 19 }, { 2, 13 }, { 7, 10 } };
//     cout << s.mostBooked(n, meetings) << endl;
// }

/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
*/
