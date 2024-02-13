#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
  int answer = 0;
  vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

  for (auto r : results)
    graph[r[0]][r[1]] = true;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        if (graph[j][i] == true && graph[i][k] == true)
        {
          graph[j][k] = true;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int count = 0;
    for (int j = 1; j <= n; j++)
    {
      if (graph[i][j] == true || graph[j][i] == true)
        count++;
    }
    if (count == n - 1)
      answer++;
  }
  return answer;
}
