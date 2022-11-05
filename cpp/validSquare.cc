class Solution {
public:
    struct Point {
        int x, y;
        Point(int _x, int _y) : x(_x), y(_y) {}
    };

    bool validSquare(vector<int>  p1, vector<int>  p2, vector<int>  p3, vector<int>  p4) {
        std::set<pair<int,int>> points;
        points.insert({p1[0], p1[1]});
        points.insert({p2[0], p2[1]});
        points.insert({p3[0], p3[1]});
        points.insert({p4[0], p4[1]});
        std::vector<double> dists;
        std::cout << points.size() << "\n";
        if (points.size() != 4) return false;
        set<double> uniq;

        for (auto& u : points) {
            for (auto& v : points) {
                if (u.first == v.first and u.second == v.second) continue;
                double dist = sqrt(pow(u.first-v.first, 2) + pow(u.second-v.second, 2));
                uniq.insert(dist);
                if (uniq.size() > 2) return false;
                // std::cout << u.x << ", " << u.y << "\t" << v.x << ", " << v.y << "\n";
                // std::cout << dist << "\n";
            }
        }

        double first{}, second{};
        auto it = uniq.begin();
        first = *it;
        second = *(next(it));
        // std::cout << "first: " << first << " second: " << second << "\n";
        const double eps = 0.0001;
        if (abs(first * sqrt(2)  - second) < eps) return true;
        if (abs(second * sqrt(2)  - first) < eps) return true;

        return false;
    }
};
