#include <string>
#include <vector>

using namespace std;

vector<int> purse(vector<int> v, int num)
{
  for (int i = 0; i < v.size(); i++)
  {
    v[i] = v[i] * num;
    num *= -1;
  }
  return v;
}

long long solution(vector<int> sequence)
{
  // 1로 시작하는 펄스 벡터
  vector<int> seq1 = purse(sequence, 1);
  // -1로 시작하는 펄스 벡터
  vector<int> seq2 = purse(sequence, -1);

  long long answer = -999999999;
  long long dp1[seq1.size()]; // 1 dp 배열
  long long dp2[seq2.size()]; // -1 dp 배열

  dp1[0] = seq1[0];
  dp2[0] = seq2[0];
  for (int i = 1; i < seq1.size(); i++)
  {
    // max로 비교위해 자료형 치환
    dp1[i] = max(dp1[i - 1] + (long long)seq1[i], (long long)seq1[i]);
    answer = max(answer, dp1[i]);
  }
  for (int i = 1; i < seq2.size(); i++)
  {
    // 아까 했던 점화식
    dp2[i] = max(dp2[i - 1] + (long long)seq2[i], (long long)seq2[i]);
    answer = max(answer, dp2[i]);
  }
  // 1일때는 그냥 둘 중 더 큰거
  if (sequence.size() == 1)
  {
    answer = max(seq1[0], seq2[0]);
    return answer;
  }
  return answer;
}