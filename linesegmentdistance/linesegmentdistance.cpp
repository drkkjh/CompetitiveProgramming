// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbl double

struct Point {
    dbl x, y;
};

dbl dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

dbl dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

dbl cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point subtract(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool segmentsIntersect(Point p1, Point q1, Point p2, Point q2) {
    double o1 = cross(subtract(q1, p1), subtract(p2, p1));
    double o2 = cross(subtract(q1, p1), subtract(q2, p1));
    double o3 = cross(subtract(q2, p2), subtract(p1, p2));
    double o4 = cross(subtract(q2, p2), subtract(q1, p2));

    if (o1 * o2 < 0 && o3 * o4 < 0) {
        return true;
    }
    if (o1 == 0 && onSegment(p1, p2, q1)) {
        return true;
    }
    if (o2 == 0 && onSegment(p1, q2, q1)) {
        return true;
    }
    if (o3 == 0 && onSegment(p2, p1, q2)) {
        return true;
    }
    if (o4 == 0 && onSegment(p2, q1, q2)) {
        return true;
    }
    return false;
}

dbl norm(Point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

dbl pointToSegmentDistance(Point p, Point a, Point b) {
    Point ap = subtract(p, a), ab = subtract(b, a);
    dbl ab2 = dot(ab, ab);
    if (ab2 == 0) { // a and b are the same point
        return norm(ap); // just return distance from p to a since p to b is equivalent as well
    }
    dbl ap_ab = dot(ap, ab);
    dbl t = ap_ab / ab2;
    if (t < 0.0) return norm(ap);
    else if (t > 1.0) return norm(subtract(p, b));
    Point c = {a.x + ab.x * t, a.y + ab.y * t};
    return norm(subtract(p, c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << fixed << setprecision(2);
    while (n--) {
        Point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        
        if (segmentsIntersect(a, b, c, d)) {
            cout << "0.00\n";
        } else {
            double minDist = min({pointToSegmentDistance(a, c, d),
                                  pointToSegmentDistance(b, c, d),
                                  pointToSegmentDistance(c, a, b),
                                  pointToSegmentDistance(d, a, b)});
            cout << minDist << "\n";
        }
    }
    return 0;
}
