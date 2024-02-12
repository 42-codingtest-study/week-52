#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> solution(int n)
{
  vector<int> answer;
  int list[n + 1][n + 1];

  memset(list, 0, sizeof(list));

  int allnum = 0;

  allnum = n * (n + 1) / 2;

  int count = 0;
  int index1 = 0;
  int index2 = -1;

  while (count != allnum)
  {
    for (int i = 0; i < n; i++)
    {
      index2 += 1;
      if (list[index2][index1] == 0)
      {
        list[index2][index1] = count + 1;
        count += 1;
      }
      else
      {
        index2 -= 1;
        break;
      }
    }

    for (int i = 0; i < n - 1; i++)
    {
      if (count == allnum)
      {
        break;
      }

      index1 += 1;
      if (list[index2][index1] == 0)
      {
        list[index2][index1] = count + 1;
        count += 1;
      }
      else
      {
        index1 -= 1;
        break;
      }
    }

    for (int i = 0; i < n - 2; i++)
    {
      index1 -= 1;
      index2 -= 1;
      if (list[index2][index1] == 0)
      {
        list[index2][index1] = count + 1;
        count += 1;
      }
      else
      {
        index1 += 1;
        index2 += 1;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (list[i][j] == 0)
      {
        break;
      }
      else
      {
        answer.push_back(list[i][j]);
      }
    }
  }

  return answer;
}
