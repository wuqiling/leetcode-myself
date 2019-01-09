#include <algorithm>
#include <map>
#include <vector>
#include <numeric>

using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
   public:
    // time O(N^2) space O(N)
    // Runtime: 8 ms, faster than 67.86%
    int maxPoints(vector<Point>& points) {
        const int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // key:val  => slope:count
            // don't use hash by no hash func for pair!!!!
            map<pair<int, int>, int> hm;
            int same_point = 1;  // self
            int max_points = 0;
            const Point& p1 = points[i];
            for (int j = i + 1; j < n; j++) {
                const Point& p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y)
                    ++same_point;
                else
                    max_points = max(max_points, ++hm[getSlope(p1, p2)]);
			}
            ans = max(ans, max_points + same_point);
        }
        return ans;
    }

   private:
    // slope = first/second = dy / dx
    pair<int, int> getSlope(const Point& p1, const Point& p2) {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;

        if (dy == 0) return {p1.y, 0};
        if (dx == 0) return {0, p1.x};
        int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }
    int gcd(int m, int n) { return n == 0 ? m : gcd(n, m % n); }
};

int main() {
    vector<Point> p{{1, 1}, {2, 2}, {3, 3}};

    Solution s;
    int ans = s.maxPoints(p);
}