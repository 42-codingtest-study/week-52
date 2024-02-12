#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int arr[2002];

// int cnt = 0;

// void recurseFunc(int cur, int n)
// {
//     if (cur == n)
//     {
//        // cout<<cur << "\n";
//         cnt++;
//         return;
//     }
//     if (cur + 1 <= n)
//     {
//        // cout << cur << " ";
//         recurseFunc(cur + 1, n);
//     }
//     if (cur + 2 <= n)
//     {
//       //  cout<<cur << " ";
//         recurseFunc(cur + 2, n);
//     }

// }

long long solution(int n)
{
  long long answer = 0;

  int dp[2002];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = dp[1] + dp[2];

  for (int i = 4; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
  }

  return dp[n];
  // return answer;
}
