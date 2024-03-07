// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
    double x, y, z;
};

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int k, m;
    while (true) {
        int hits = 0;
        cin >> k >> m;
        if (k == 0 & m == 0) {
            break;
        }
        vector<Point> satellites(k);
        vector<Point> depressions(m);
        vector<bool> hitDepressions(m, false);
        for (int i = 0; i < k; i++) {
            cin >> satellites[i].x >> satellites[i].y >> satellites[i].z;
        }
        for (int j = 0; j < m; j++) {
            cin >> depressions[j].x >> depressions[j].y >> depressions[j].z;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (!hitDepressions[j]) {
                    // Vector from earth to depressions
                    Point earthToDepression = {0 - depressions[j].x, 0 - depressions[j].y, 0 - depressions[j].z};
                    // Vector from satellite to depression
                    Point satelliteToDepression = {satellites[i].x - depressions[j].x, satellites[i].y - depressions[j].y, satellites[i].z - depressions[j].z}; 
                    // Compute the dot product here, because if dot product > 0 means the angle is acute and there is no way
                    // that the target is in the line of sight of the satellite
                    if (dot(earthToDepression, satelliteToDepression) > 0) {
                        continue;
                    } else {
                        hits++;
                        hitDepressions[j] = true;
                    }
                }   
            }
        }
        cout << hits << "\n";
    }
};