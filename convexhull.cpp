#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef long long ll;

struct Line {
    ll slope, intercept;

    // Compute y = mx + b at point x
    ll value_at(ll x) {
        return slope * x + intercept;
    }

    // Check if line a is "worse" than line b and c
    // This uses a mathematical trick to avoid floating point precision issues.
    bool is_worse_than(const Line& a, const Line& b) {
        return (intercept - a.intercept) * (a.slope - b.slope) >= (a.intercept - b.intercept) * (slope - a.slope);
    }
};

class ConvexHullTrick {
    deque<Line> hull;

public:
    // Add a new line with slope m and intercept c
    void add_line(ll slope, ll intercept) {
        Line new_line = {slope, intercept};

        // Remove lines from the back that are no longer necessary
        while (hull.size() >= 2 && new_line.is_worse_than(hull[hull.size() - 2], hull.back())) {
            hull.pop_back();
        }
        hull.push_back(new_line);
    }

    // Find the minimum value at point x
    ll get_minimum(ll x) {
        // Make sure the front line is the best for the current x
        while (hull.size() >= 2 && hull[0].value_at(x) >= hull[1].value_at(x)) {
            hull.pop_front();
        }
        return hull.front().value_at(x);
    }
};

int main() {
    ConvexHullTrick cht;

    // Add lines: y = mx + b
    cht.add_line(3, 5);   // Line with slope 3, intercept 5
    cht.add_line(2, 10);  // Line with slope 2, intercept 10
    cht.add_line(1, 20);  // Line with slope 1, intercept 20

    // Query minimum value at different x values
    cout << "Minimum at x = 5: " << cht.get_minimum(5) << endl;  // Query at x = 5
    cout << "Minimum at x = 10: " << cht.get_minimum(10) << endl;  // Query at x = 10
    cout << "Minimum at x = 15: " << cht.get_minimum(15) << endl;  // Query at x = 15

    return 0;
}
