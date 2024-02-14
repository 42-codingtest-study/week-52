#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int n, m, x, y;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> board(1001, vector<int>(1001, 0));
vector<vector<int>> visited(1001, vector<int>(1001, 0));

int main() {
  fast;
  queue<pair<int, int>> q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) x = i, y = j;
    }
  }
  q.push({x, y});
  visited[x][y] = 1;
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int ni = i + d[k][0];
      int nj = j + d[k][1];
      if (0 <= ni && ni < n && 0 <= nj && nj < m && !visited[ni][nj] &&
          board[ni][nj] == 1) {
        visited[ni][nj] = visited[i][j] + 1;
        q.push({ni, nj});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (!visited[i][j] ? board[i][j] == 1 ? -1 : visited[i][j]
                              : visited[i][j] - 1)
           << " ";
    }
    cout << endl;
  }
}
