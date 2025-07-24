#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> result = vector(m, vector(n, 0));
    queue<pair<pair<int, int>, int>> distances;
    set<pair<int, int>> visited;

    // Iterate through matrix and add all zeros to matrix with step 0
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          visited.insert({i, j});
          distances.push({{i, j}, 0});
        }
      }
    }

    // Perform Breadfirst Search on all nodes that have been visited
    while (!distances.empty()) {
      auto [point, s] = distances.front();
      auto [x, y] = point;
      result[x][y] = s;
      distances.pop();

      for (auto [dx, dy] : directions) {
        int r = x + dx;
        int c = y + dy;

        if (r < 0 || c < 0 || r >= mat.size() || c >= mat[r].size()) {
          continue;
        }

        if (visited.find({r, c}) != visited.end()) {
          continue;
        }

        visited.insert({r, c});
        distances.push({{r, c}, s + 1});
      }
    }

    return result;
  }
};
