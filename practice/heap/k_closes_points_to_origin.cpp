// Given a list of points on the 2-D plane and an integer K. 
// The task is to find K closest points to the origin and print them.
// Note: The distance between two points on a plane is the Euclidean distance.
// Example:
// Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2 . 

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> pvi;

int main() {
    vector<vector<int>> points;
    int n;

    cout << "Enter the number of points:- ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> point;
        int x, y;
        cout << "Enter x-coordinate for point " << i << ":- ";
        cin >> x;
        cout << "Enter y-coordinate for point " << i << ":- ";
        cin >> y;
        point.push_back(x);
        point.push_back(y);
        points.push_back(point);
        point.clear();
    }

    int k;

    cout << "Enter value of k:- ";
    cin >> k;

    priority_queue<pvi> max_heap;
    vector<vector<int>> ans;
    for (const auto& pt : points) {
        int distance = pt[0] * pt[0] + pt[1] * pt[1];
        max_heap.push({ distance, pt });

        while (max_heap.size() > k) {
            max_heap.pop();
        }
    }
    while (max_heap.size() > 0) {
        ans.push_back(max_heap.top().second);
        max_heap.pop();
    }

    cout << "\nThe " << k << " closest points to origin are:" << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << "Point " << i << ": [" << ans[i][0] << ", " << ans[i][1] << "]";

        // Calculate and display actual distance for clarity
        double actualDistance = sqrt(ans[i][0] * ans[i][0] + ans[i][1] * ans[i][1]);
        cout << " (Distance: " << fixed << setprecision(2) << actualDistance << ")" << endl;
    }

    return 0;
}