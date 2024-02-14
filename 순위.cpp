#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
  int answer = 0;
  vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
  for (auto r : results) graph[r[0]][r[1]] = true;
  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= n; j++) {
      for (size_t k = 1; k <= n; k++) {
        if (graph[j][i] && graph[i][k]) {
          graph[j][k] = true;
        }
      }
    }
  }
  for (size_t i = 1; i <= n; i++) {
    int count = 0;
    for (size_t j = 1; j <= n; j++)
      if (graph[i][j] || graph[j][i]) count++;
    if (count == n - 1) answer++;
  }
  return answer;
}

int main() {
  int n = 5;
  vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
  cout << solution(n, results) << " == 2\n";
}
