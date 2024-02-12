#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n)
{
  int ans = 0;

  // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

  while (n != 0)
  {
    if (n % 2 == 0)
      n /= 2;
    else if (n % 2 == 1)
    {
      ans++;
      n--;
      n /= 2;
    }
  }
  cout << "Hello Cpp" << endl;

  return ans;
}
