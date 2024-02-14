#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool visited[104][104];
int dist[104][104], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int solution(vector<vector<int>> m) {
  int ans = 0, ns = m.size(), ms = m[0].size();
  memset(dist, -1, sizeof(dist));
  q.push({0, 0});
  visited[0][0] = 1, dist[0][0] = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.first == ns - 1 && cur.second == ms - 1)
      return dist[ns - 1][ms - 1];
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.second + dx[dir], ny = cur.first + dy[dir];
      if (nx < 0 || ny < 0 || nx >= ms || ny >= ns) continue;
      if (visited[ny][nx] || m[ny][nx] == 0 || dist[ny][nx] != -1) continue;
      q.push({ny, nx});
      visited[ny][nx], dist[ny][nx] = dist[cur.first][cur.second] + 1;
    }
  }
  return (dist[ns - 1][ms - 1] == -1 ? -1 : dist[ns - 1][ms - 1]);
}
