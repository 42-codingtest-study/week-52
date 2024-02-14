#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M, maxValue = 0;
int board[500][500];
bool visited[500][500];

void dfs(int i, int j, int dsum, int cnt) {
  if (cnt == 4) {
    maxValue = max(maxValue, dsum);
    return;
  }
  for (int n = 0; n < 4; n++) {
    int ni = i + d[n][0];
    int nj = j + d[n][1];
    if (0 <= ni && ni < N && 0 <= nj && nj < M && !visited[ni][nj]) {
      visited[ni][nj] = true;
      dfs(ni, nj, dsum + board[ni][nj], cnt + 1);
      visited[ni][nj] = false;
    }
  }
}

void exce(int i, int j) {
  for (int n = 0; n < 4; n++) {
    int tmp = board[i][j];
    for (int k = 0; k < 3; k++) {
      int ni = i + d[(n + k) % 4][0];
      int nj = j + d[(n + k) % 4][1];
      if (0 <= ni && ni < N && 0 <= nj && nj < M) {
        tmp += board[ni][nj];
      } else {
        tmp = 0;
        break;
      }
    }
    maxValue = max(maxValue, tmp);
  }
}

int main() {
  fast;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> board[i][j];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = true;
      dfs(i, j, board[i][j], 1);
      visited[i][j] = false;
      exce(i, j);
    }
  }
  cout << maxValue;
}
