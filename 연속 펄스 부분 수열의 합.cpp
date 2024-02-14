#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll solution(vector<int> sequence) {
  ll currentMax1 = sequence[0], currentMax2 = -sequence[0],
     maxPulseSum = max(sequence[0], -sequence[0]);
  for (int i = 1; i < sequence.size(); ++i) {
    if (i % 2 == 0)
      currentMax1 = max(currentMax1 + sequence[i], (ll)sequence[i]),
      currentMax2 = max(currentMax2 - sequence[i], -(ll)sequence[i]);
    else
      currentMax1 = max(currentMax1 - sequence[i], -(ll)sequence[i]),
      currentMax2 = max(currentMax2 + sequence[i], (ll)sequence[i]);
    maxPulseSum = max(maxPulseSum, max(currentMax1, currentMax2));
  }
  return maxPulseSum;
}

int main() {
  vector<int> sequence = {2, 3, -6, 1, 3, -1, 2, 4};
  cout << solution(sequence) << " == 10\n";
  return 0;
}
